const Wishlist = require('../models/wishlist');

// get wishilist uzytkownika
exports.getMyWishlist = async (req, res) => {
  try {
    const wishlist = await Wishlist.find({ user: req.user._id });
    res.status(200).json({ data: wishlist, message: 'Twoja wishlist' });
  } catch (error) {
    res.status(500).json({ message: 'Błąd serwera' });
  }
};

// Add wishlist edla uzytkownika
exports.addToMyWishlist = async (req, res) => {
  try {
    const { title, description, price } = req.body;
    if (!title) {
      return res.status(400).json({ message: 'Tytuł jest wymagany' });
    }
    const newEntry = new Wishlist({
      user: req.user._id,
      title,
      description,
      price
    });
    await newEntry.save();
    res.status(201).json({ data: newEntry, message: 'Dodano do wishlisty' });
  } catch (error) {
    res.status(500).json({ message: 'Błąd serwera' });
  }
};

// zmien status wishlist dlas uzytkownika
exports.togglePurchased = async (req, res) => {
  try {
    const { id } = req.params;
    const entry = await Wishlist.findOne({ _id: id, user: req.user._id });
    if (!entry) return res.status(404).json({ message: 'Nie znaleziono wpisu' });
    entry.purchased = !entry.purchased;
    await entry.save();
    res.status(200).json({ data: entry, message: 'Status zakupu zmieniony' });
  } catch (error) {
    res.status(500).json({ message: 'Błąd serwera' });
  }
};

// usunc wishlist dla uzytkownika
exports.deleteWishlistEntry = async (req, res) => {
  try {
    const { id } = req.params;
    const entry = await Wishlist.findOne({ _id: id, user: req.user._id });
    if (!entry) return res.status(404).json({ message: 'Nie znaleziono wpisu' });
    
    await Wishlist.findByIdAndDelete(id);
    res.status(200).json({ message: 'Wpis został usunięty' });
  } catch (error) {
    res.status(500).json({ message: 'Błąd serwera' });
  }
};

// get statystyki wishlisty uzytkownika
exports.getMyWishlistStats = async (req, res) => {
  try {
    const wishlist = await Wishlist.find({ user: req.user._id });
    
    const totalEntries = wishlist.length;
    const purchasedEntries = wishlist.filter(item => item.purchased).length;
    const accomplishedPercentage = totalEntries > 0 ? Math.round((purchasedEntries / totalEntries) * 100) : 0;
    
    const totalValue = wishlist.reduce((sum, item) => sum + (item.price || 0), 0);
    const totalSpent = wishlist.filter(item => item.purchased).reduce((sum, item) => sum + (item.price || 0), 0);
    const remainingValue = totalValue - totalSpent;
    
    const stats = {
      totalEntries,
      purchasedEntries,
      accomplishedPercentage,
      totalValue: Math.round(totalValue * 100) / 100,
      totalSpent: Math.round(totalSpent * 100) / 100,
      remainingValue: Math.round(remainingValue * 100) / 100
    };
    
    res.status(200).json({ data: stats, message: 'Wishlist statistics' });
  } catch (error) {
    res.status(500).json({ message: 'Server error' });
  }
};
