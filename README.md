# cppt

Write templates in C preprocessor language.

## Example

```
./cppt -D'users(u)=u("Jesus",2015)u("Alice",17)u("Max",-1)' <example/example.cppt
```

The output is a chunk of HTML:

```html
<table class="users" id="my-table"><tr><td>Jesus</td><td>2015</td></tr><tr><td>Alice</td><td>17</td></tr><tr><td>Max</td><td>-1</td></tr></table>
```

## License

MIT
