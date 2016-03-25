Commands
--------

```
w -> increase both wheels
a -> decrease both wheels
d -> increase right wheel
s -> decrease right wheel
x -> brake
```


Reading chars in Ruby
---------------------

```ruby
require 'io/console'

$stdin.raw {
  10.times {
    case $stdin.getc
    when "w" then print "up\r\n"
    when "s" then print "\down\r\n"
    when "d" then print "right\r\n"
    when "a" then print "left\r\n"
    end
  }
}
```

