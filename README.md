# Ruby bindings for lzfx

lzfx is a tiny, extremely fast compression library.

## lzfx
this gem contains lzfx.

* http://code.google.com/p/lzfx/

> LZFX is a small (one C file, 200 non-comment lines) BSD-licensed library designed for very-high-speed compression of redundant data. It is descended from liblzf and is 100% compatible with existing LZF-compressed data.

> LZFX was originally developed as a component of the h5py project, which uses an LZF-based compressor to process scientific data.

## Example

```ruby
require 'rubygems'
require 'lzfx'

a = "aaaaaaaaabbbbbbbbbbbbabababaccccccccccjshabbbbbbaaa"
puts "source: #{a}"
puts "source size: #{a.size}"

b = Lzfx.compress a
puts "compressed: #{b}"
puts "compressed size: #{b.size}"

c = Lzfx.decompress b
puts "decompressed: #{c}"
puts "decompressed size: #{c.size}"
puts "source == decompressed: #{a == c}"
```

## Copyright
Copyright: (C) 2012 Kengo HAMASAKI <k.hamasaki@gmail.com>
