#include <string.h>
#include "ruby.h"
#define COFFICIENT_OF_BUFFER 3

static VALUE rb_lzfx_compress(VALUE self, VALUE input) {
  unsigned char *compressed, *data;
  int out_length, data_length;
  int retcode;
  VALUE retval;

  Check_Type(input, T_STRING);
  data = StringValuePtr(input);
  data_length = RSTRING_LEN(input);

  if (data_length < 1) {
    return Qnil;
  }

  out_length = data_length * COFFICIENT_OF_BUFFER;
  compressed = malloc(out_length);

  retcode = lzfx_compress(data, data_length, compressed, &out_length);

  if(retcode < 0) {
    ruby_xfree(compressed);
    return Qnil;
  }

  retval = rb_str_new(compressed, out_length);

  ruby_xfree(compressed);

  return retval;
}

static VALUE rb_lzfx_decompress(VALUE self, VALUE input) {
  unsigned char *decompressed, *data;
  int out_length, data_length;
  int retcode;
  VALUE retval;

  Check_Type(input, T_STRING);

  data = RSTRING_PTR(input);
  data_length = RSTRING_LEN(input);

  if (data_length < 1) {
    return Qnil;
  }

  out_length = data_length * COFFICIENT_OF_BUFFER;
  decompressed = malloc(out_length);

  retcode = lzfx_decompress(data, data_length, decompressed, &out_length);

  if(retcode < 0) {
    ruby_xfree(decompressed);
    return Qnil;
  }

  retval = rb_str_new(decompressed, out_length);

  ruby_xfree(decompressed);

  return retval;
}

void Init_lzfx() {
  VALUE rb_mLzfx;
  rb_mLzfx = rb_define_module("Lzfx");
  rb_define_module_function(rb_mLzfx, "compress", rb_lzfx_compress, 1);
  rb_define_module_function(rb_mLzfx, "decompress", rb_lzfx_decompress, 1);
}
