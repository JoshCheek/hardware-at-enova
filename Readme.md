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
    when "s" then print "down\r\n"
    when "d" then print "right\r\n"
    when "a" then print "left\r\n"
    end
  }
}
```

Writing to pins
---------------

There is a program in the root called like gpio-admin.
It lets you write to the pins.
I took the code from [here](https://github.com/quick2wire/quick2wire-gpio-admin)

```
$ sudo gpio-admin export 7
$ echo out > /sys/devices/virtual/gpio/gpio7/direction
$ echo 1 > /sys/devices/virtual/gpio/gpio7/value
```

Despite choosing pin 7, the wire is pin 26.
I figured that out by comparing [this](http://www.jameco.com/Jameco/workshop/circuitnotes/raspberry-pi-circuit-note.html)
chart to [this](https://github.com/quick2wire/quick2wire-python-api/blob/c5e21e9d804012efd9d214d18909034b4b898c96/quick2wire/gpio.py#L274)
map.
