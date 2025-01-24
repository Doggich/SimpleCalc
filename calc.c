#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <math.h>
#include <errno.h>

long double pow_number(long double number, int grade) {
    long double temp_number = 1;
    for (int i = 0; i < grade; i++) {
        temp_number *= number;
    }
    return temp_number;
}

long double cosine(long double x) {
    long double  radians = x * M_PI / 180;
    long double  sum_ = 0;
    long double  term = 1;
    int n = 0;

    while (fabs(term) > 1e-6) {
        sum_ += term;
        n += 2;
        term *= -1 * radians * radians / (n * (n - 1));
    }

    return sum_;
}

long double  sine(long double  x) {
    long double  radians = x * M_PI / 180;
    long double  sum_ = 0;
    long double  term = radians;
    int n = 1;

    while (fabs(term) > 1e-6) {
        sum_ += term;
        n += 2;
        term *= -1 * radians * radians / (n * (n - 1));
    }

    return sum_;
}

long double  tangence(long double  x) {
    return sine(x) / cosine(x);
}

long double  cotangence(long double  x) {
    return cosine(x) / sine(x);
}

int gcd(int numberA, int numberB) {
    while (numberA != numberB) {
        if (numberA > numberB) {
            numberA -= numberB;
        } else {
            numberB -= numberA;
        }
    }
    return numberA;
}

long double parse_number(const char *str) {
    if (strcmp(str, "pi") == 0) {
        return M_PI;
    } else if (strcmp(str, "e") == 0) {
        return M_E;
    } else {
        char *endptr;
        errno = 0;
        long double result = strtold(str, &endptr);
        if (errno != 0 || *endptr != '\0') {
            fprintf(stderr, "Error: Invalid number '%s'\n", str);
            exit(1);
        }
        return result;
    }
}

void print_help(const char *program_name) {
    printf("Operations: add, sub, mul, div, pow, cos, sin, tg, ctg, gcd.\n");
    printf("Syntax: %s <operation> <number1> <number2>\n", program_name);
    printf("Special values: 'pi' for π, 'e' for e\n");
}

int main(int argc, char *argv[]) {
    if (argc == 2 && strcmp(argv[1], "help") == 0) {
        print_help(argv[0]);
        return 0;
    }

    if (argc != 4) {
        fprintf(stderr, "Usage: %s <operation> <number1> <number2>\n", argv[0]);
        return 1;
    }

    const char *operation = argv[1];
    long double number1 = parse_number(argv[2]);
    long double number2 = parse_number(argv[3]);

    long double result;
    int int_result;

    if (strcmp(operation, "add") == 0) {
        result = number1 + number2;
    } else if (strcmp(operation, "sub") == 0) {
        result = number1 - number2;
    } else if (strcmp(operation, "mul") == 0) {
        result = number1 * number2;
    } else if (strcmp(operation, "div") == 0) {
        if (number2 == 0) {
            fprintf(stderr, "Error: Division by zero\n");
            return 1;
        }
        result = number1 / number2;
    } else if (strcmp(operation, "pow") == 0) {
        result = pow_number(number1, (int)number2);
    } else if (strcmp(operation, "cos") == 0) {
        result = cosine(number1);
    } else if (strcmp(operation, "sin") == 0) {
        result = sine(number1);
    } else if (strcmp(operation, "tg") == 0) {
        result = tangence(number1);
    } else if (strcmp(operation, "ctg") == 0) {
        result = cotangence(number1);
    } else if (strcmp(operation, "gcd") == 0) {
        int_result = gcd((int)number1, (int)number2);
        printf("%d\n", int_result);
        return 0;
    } else {
        fprintf(stderr, "Error: Unknown operation '%s'\n", operation);
        return 1;
    }

    printf("%.10Lf\n", result);
    return 0;
}
