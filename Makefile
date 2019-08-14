build: main.c
	gcc table.c compiler.c core.c main.c -o tsql

run: tsql
	./tsql

clean:
	rm -f tsql

test: tsql
	bundle exec rspec --format doc test/main_test.rb

format: *.c
	clang-format -style=Google -i *.c