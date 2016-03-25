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
