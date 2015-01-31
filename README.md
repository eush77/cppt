# cppt

Write templates in C preprocessor language.

## Example

```
./cppt -D'TITLE="cppt_demo_#1"' -D'USERS(u)=u("Jesus",2015)u("Alice",17)u("Max",-1)' <example/example.cppt
```

The output is a chunk of HTML:

```html
<!doctype html>
<html>
<head><title>cppt_demo_#1</title></head>
<body>
<h1>Users:</h1>
<table class="users" id="my-table">
<tr><td>Jesus</td><td>2015</td></tr>
<tr><td>Alice</td><td>17</td></tr>
<tr><td>Max</td><td>-1</td></tr>
</table>
</body>
</html>
```

And here is what the template itself looks like:

```c
#define html doctype t("html", "", head body)
#define doctype "<!doctype html>\n"

#define head "\n" t("head", "", title)
#define title t("title", "", TITLE)

#define body "\n" t("body", "", h1 table) "\n"
#define h1 "\n" t("h1", "", "Users:")
#define table "\n" t("table", a("class", "users") a("id", "my-table"), "\n" USERS(table_row)) "\n"
#define table_row(user, age) t("tr", "", t("td", "", user) t("td", "", #age)) "\n"
```

## License

MIT
