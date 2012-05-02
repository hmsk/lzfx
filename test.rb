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
