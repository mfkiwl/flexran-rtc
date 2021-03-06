/* The MIT License (MIT)

   Copyright (c) 2016 Xenofon Foukas

   Permission is hereby granted, free of charge, to any person obtaining a copy
   of this software and associated documentation files (the "Software"), to deal
   in the Software without restriction, including without limitation the rights
   to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
   copies of the Software, and to permit persons to whom the Software is
   furnished to do so, subject to the following conditions:
   
   The above copyright notice and this permission notice shall be included in all
   copies or substantial portions of the Software.
   
   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
   IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
   AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
   LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
   OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
   SOFTWARE.
*/

#ifndef PROTOCOL_MESSAGE_H_
#define PROTOCOL_MESSAGE_H_

#include "flexran.pb.h"

namespace flexran {

  namespace network {
    
    class protocol_message {
      
    public:
      enum { header_length = 4 };
      enum { max_body_length = 240000 };
      
    protocol_message()
      : body_length_(0) {}
      
      const char* data() const {
	return (char *) data_;
      }
      
      char* data() {
	return (char *) data_;
      }
      
      uint32_t length() const {
	return header_length + body_length_;
      }
      
      const char* body() const {
	return (char *) data_ + header_length;
      }
      
      char* body() {
	return (char *) data_ + header_length;
      }
      
      std::size_t body_length() const {
	return body_length_;
      }
      
      void body_length(std::size_t new_length);
      
      void set_message(const char * buf, std::size_t size);
      
      bool decode_header();
      
      void encode_header();
      
    private:
      unsigned char data_[header_length + max_body_length];
      uint32_t body_length_;
      
    };
    
  }
}

#endif
