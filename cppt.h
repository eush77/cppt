#define t1(tag, attributes) "<" tag attributes ">"

#define t(tag, attributes, body) t1(tag, attributes) body "</" tag ">"

#define a(key, value) " " key "=\"" value "\""
