function getDate() {
    const now = new Date();
    return now.toISOString();
}

module.exports = getDate;