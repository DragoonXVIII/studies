const express = require('express');
const router = express.Router();
const tokenVerification = require('../middleware/tokenVerification');
const wishlistController = require('../controllers/wishlistController');

// GET /api/wishlist/my - get wishlist for logged-in user
router.get('/my', tokenVerification, wishlistController.getMyWishlist);

// POST /api/wishlist/my - add new wishlist entry for logged-in user
router.post('/my', tokenVerification, wishlistController.addToMyWishlist);

// PATCH /api/wishlist/:id/toggle - toggle purchased status
router.patch('/:id/toggle', tokenVerification, wishlistController.togglePurchased);

// DELETE /api/wishlist/:id - delete wishlist entry
router.delete('/:id', tokenVerification, wishlistController.deleteWishlistEntry);

// GET /api/wishlist/stats - get wishlist statistics for logged-in user
router.get('/stats', tokenVerification, wishlistController.getMyWishlistStats);

module.exports = router;
