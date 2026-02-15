#include <iostream>
#include <string>
#include "exprtk.hpp" // Assuming exprtk.hpp is in your include path

int main() {
    // Define types for clarity
    using symbol_table_t = exprtk::symbol_table<double>;
    using expression_t   = exprtk::expression<double>;
    using parser_t       = exprtk::parser<double>;

    // The expression string
    const std::string expression_string = "z := x - (3 * y) + 5";

    // Define and initialize variables that will be used in the expression
    double x = 100.0;
    double y = 5.0;
    double z = 0.0; // z will hold the result because of the assignment operator ":="

    // Create and populate the symbol table
    symbol_table_t symbol_table;
    symbol_table.add_variable("x", x);
    symbol_table.add_variable("y", y);
    symbol_table.add_variable("z", z);
    
    // The expression object is linked to the symbol table
    expression_t expression;
    expression.register_symbol_table(symbol_table);

    // Compile the expression
    parser_t parser;
    if (parser.compile(expression_string, expression)) {
        // Evaluate the expression
        double result = expression.value(); 
        std::cout << "Result: " << result << std::endl; // Prints Result: 90
    } else {
        std::cout << "Error: Invalid expression" << std::endl;
    }

    return 0;
}