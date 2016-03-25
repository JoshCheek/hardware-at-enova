#include "stdio.h"
#define BUFFER_LENGTH 10


typedef struct {
  int inputs[BUFFER_LENGTH];
  int ready;
  int value;
} MyBuf;

MyBuf new_buf() {
  MyBuf buffer;
  int i;
  for(i = 1; i < BUFFER_LENGTH; ++i) {
    buffer.inputs[i] = 0;
  }
  buffer.ready = 0;
  buffer.value = -1;
  return buffer;
}

void add(MyBuf *buffer, int on) {
  int i;
  for(i=1; i < BUFFER_LENGTH; ++i) {
    buffer->inputs[i-1] = buffer->inputs[i];
  }
  buffer->inputs[BUFFER_LENGTH-1] = on;
}

void find_value(MyBuf *buffer) {
  int i;
  for(i=0; i < BUFFER_LENGTH && !buffer->inputs[i]; ++i) {
    ;
  }
  if(i+3 < BUFFER_LENGTH) {
    int a, b, c;
    a = buffer->inputs[i+1];
    b = buffer->inputs[i+2];
    c = buffer->inputs[i+3];
    buffer->value = 4*a + 2*b + c;
  }
}

void input(MyBuf *buffer, int on) {
  add(buffer, on);
  find_value(buffer);
}

void on(MyBuf *buffer) {
  input(buffer, 1);
}

void off(MyBuf *buffer) {
  input(buffer, 0);
}

void buffer_inputs_to_s(MyBuf *buffer, char*str) {
  int i;
  for(i=0; i<BUFFER_LENGTH; ++i)
    str[i] = (buffer->inputs[i] ? '1' : '0');
  str[i] = 0;
}


int main() {
  MyBuf buffer = new_buf();

  char c = ' ';
  while(c != 'q') {
    c = getchar();
    getchar(); // toss the return
    if(c == '1') {
      on(&buffer);
    } else if (c == '0') {
      off(&buffer);
    } else {
      printf("Enter 0s and 1s\r\n");
    }
    printf("Value:  %d\n", buffer.value);
    char str[BUFFER_LENGTH+1];
    buffer_inputs_to_s(&buffer, str);
    printf("Inputs: %s\n", str);
  }
  return(0);
}
