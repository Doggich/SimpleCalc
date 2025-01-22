#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <math.h>

int pow_number(int number, int grade) {
    int temp_number = 1;
    for (int i = 0; i < grade; i++) {
        temp_number *= number;
    }
    return temp_number;
}

float cosine(float x) {
    float radians = x * M_PI / 180;
    float sum_ = 0;
    float term = 1;
    int n = 0;

    while (fabs(term) > 1e-6) {
        sum_ += term;
        n += 2;
        term *= -1 * radians * radians / (n * (n - 1));
    }

    return sum_;
}

float sine(float x) {
    float radians = x * M_PI / 180;
    float sum_ = 0;
    float term = radians;
    int n = 1;

    while (fabs(term) > 1e-6) {
        sum_ += term;
        n += 2;
        term *= -1 * radians * radians / (n * (n - 1));
    }

    return sum_;
}

float tangence(float x) {
    return sine(x) / cosine(x);
}

float cotangence(float x) {
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

int main(int argc, char *argv[]) {
    if (argc == 2 && strcmp(argv[1], "help") == 0) {
        printf("Operations: add, sub, mul, div, pow, cos, sin, tg, ctg, gcd.\nSyntax: %s <operation> <number1> <number2>\n", argv[0]);
        return 0;
    }
    if (argc != 4) {
        printf("Usage: %s <operation> <number1> <number2>\n", argv[0]);
        return 1;
    }

    char *operation = argv[1];
    float number1, number2;

    if (strcmp(argv[2], "pi") == 0) {
        number1 = M_PI;
    }
    else if (strcmp(argv[2], "e") == 0)
    {
       number1 = M_E;
    }
    else {
        number1 = atof(argv[2]);
    }

    if (strcmp(argv[3], "pi") == 0) {
        number2 = M_PI;
    }
    else if (strcmp(argv[3], "e") == 0) 
    {
       number2 = M_E;
    }
    else {
        number2 = atof(argv[3]);
    }

    if (strcmp(operation, "add") == 0) {
        printf("%f\n", number1 + number2);
    } else if (strcmp(operation, "sub") == 0) {
        printf("%f\n", number1 - number2);
    } else if (strcmp(operation, "mul") == 0) {
        printf("%f\n", number1 * number2);
    } else if (strcmp(operation, "div") == 0) {
        if (number2 == 0) {
            printf("Division by zero\n");
            return 1;
        }
        printf("%f\n", number1 / number2);
    } else if (strcmp(operation, "pow") == 0) {
        printf("%d\n", pow_number((int)number1, (int)number2));
    } else if (strcmp(operation, "cos") == 0) {
        printf("%f\n", cosine(number1));
    } else if (strcmp(operation, "sin") == 0) {
        printf("%f\n", sine(number1));
    } else if (strcmp(operation, "tg") == 0) {
        printf("%f\n", tangence(number1));
    } else if (strcmp(operation, "ctg") == 0) {
        printf("%f\n", cotangence(number1));
    } else if (strcmp(operation, "gcd") == 0) {
        printf("%d\n", gcd((int)number1, (int)number2));
    } else {
        printf("Unknown operation: %s\n", operation);
        return 1;
    }

    return 0;
}
