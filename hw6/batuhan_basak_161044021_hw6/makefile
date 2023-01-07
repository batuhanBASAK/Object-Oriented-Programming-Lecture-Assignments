all: clean compile run


#removes .class files
clean:
	@rm -rf *.class


# compiles .java files
compile: *.java
	@javac *.java

# clears the screen and runs the program.
run:
	@clear
	@java Demo


# makes a documentation.
# To make document run `make make_document` and open index.html file
# in document directory.
make_document:
	@rm -rf ./document
	@mkdir ./document
	@javadoc *.java -d ./document
