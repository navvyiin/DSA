const map = new Map();
const base = "http://tinyurl.com/";
let id = 0;

var encode = function(longUrl) {
    id++;
    map.set(id, longUrl);
    return base + id;
};

var decode = function(shortUrl) {
    const key = shortUrl.replace(base, "");
    return map.get(Number(key));
};