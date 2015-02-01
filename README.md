# cppt

![status|proof of concept](https://img.shields.io/badge/status-proof_of_concept-lightgrey.svg?style=flat-square)

Write templates in C preprocessor language.

## Example

```
./cppt -D'TITLE="cppt_demo_#1"' -D'USERS(u)=u("Jesus",2015)u("Alice",17)u("Max",-1)' <example/example.cppt
```

The output is a chunk of HTML:

```html
<!doctype html>
<html><head>
<title>cppt_demo_#1</title>
<meta name="description" content="Example page">
</head><body>
<h1>Users:</h1>
<table class="users" id="my-table">
<tr><td>Jesus</td><td>2015</td></tr>
<tr><td>Alice</td><td>17</td></tr>
<tr><td>Max</td><td>-1</td></tr>
</table>
</body></html>
```

And here is what the template itself looks like:

```c
#define html doctype t("html", "", head body)
#define doctype "<!doctype html>\n"

#define head t("head", "", title description "\n")
#define title "\n" t("title", "", TITLE)
#define description "\n" t1("meta",                                     \
                            a("name", "description")                    \
                            a("content", "Example page"))

#define body t("body", "", h1 table)
#define h1 "\n" t("h1", "", "Users:")
#define table "\n" t("table",                                           \
                     a("class", "users") a("id", "my-table"),           \
                     "\n" USERS(table_row)) "\n"
#define table_row(user, age) t("tr", "",                                \
                               t("td", "", user) t("td", "", #age)) "\n"
```

## Preprocessor templates

Cppt template files must `#define` the `html` symbol as a string - the result of applying the template.

A few primitives are built in.

### `t(tag, attributes, content)`

Creates a tag with given attributes and content.

### `t1(tag, attributes)`

Creates a void (a.k.a. self-closing) tag with no content.

### `a(key, value)`

Creates an attribute. Can be combined with other attributes to form the `attributes` string containing all of them.

## CLI

```
Usage:  cppt [-D<definition>]... <TEMPLATE
```

Definitions have to be in exactly the same format as described in GCC(1).

Note: to pass a sequence of objects, you create a definition that accepts another macro, applies it to each object in a sequence and then concatenates the results. See the example.

## License

MIT
