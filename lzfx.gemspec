Gem::Specification.new do |spec|
  spec.name              = 'lzfx'
  spec.version           = '0.1.1'
  spec.summary           = 'Ruby bindings for lzfx.'
  spec.description       = 'Ruby bindings for lzfx. lzfx is a tiny, extremely fast compression library.'
  spec.files             = Dir.glob("ext/*.{c,h}") + %w(ext/extconf.rb README.md)
  spec.author            = 'hmsk'
  spec.email             = 'k.hamasaki@gmail.com'
  spec.homepage          = 'https://github.com/hmsk/lzfx'
  spec.extensions        = 'ext/extconf.rb'
  spec.has_rdoc          = true
  spec.rdoc_options      << '--title' << 'lzfx - Ruby bindings for lzfx.' << '--main' << 'README.md'
  spec.extra_rdoc_files  = %w(README.md)
end
