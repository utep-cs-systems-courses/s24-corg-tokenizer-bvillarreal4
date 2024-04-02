OBJS = history.o tokens.o uimain.o

CFLAGS = -g -O3

all: tokenizer

tokenizer: $(OBJS)
	cc -o tokenizer $(CFLAGS) $(OBJS)

$(OBJS): tokenizer.h history.h

clean:
	rm -f *.o tokernizer

run: tokenizer
	./tokenizer
