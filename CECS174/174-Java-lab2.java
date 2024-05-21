import java.util.Scanner;
import java.lang.Math;

class ScannerDemo {

    public static void main(String[] args) {
        // LabJavaPrimitiveType (first part of lab)

        // Java has 8 primitive types.
        // The integral types: byte, short, int, long
        byte byteN = 93;
        System.out.println("byteNum is "+ byteN + " and is type byte");

        short shortN = 4280;
        System.out.println("shortNum is "+ shortN + " and is type short");

        int intN = -578944;
        System.out.println("intNum is "+ intN + " and is type int");

        long longN = 578567257;
        System.out.println("longNum is "+ longN + " and is type long");

        // The floating-point types: float, double
        float floatN = 4783;
        System.out.println("floatNum is "+ floatN + " and is type float");

        double doubleN = 2.574897589423;
        System.out.println("doubleNum is "+ doubleN + " and is type double");

        // The other types: boolean, char
        boolean booleanV = true;
        System.out.println("booleanVal is "+ booleanV + " and is type boolean");

        char charV = 'w';
        System.out.println("charVal is "+ charV + " and is type char");

        // Arithmetic operators:
        // +, -, *, /, %
        int num1 = 17;
        int num2 = 4;
        System.out.println("num1 is " + num1 + " and num2 is " + num2);
        int numSum = num1 + num2;
        System.out.println("num1 + num2 is " + numSum);
        int numDif = num1 - num2;
        System.out.println("num1 - num2 is " + numDif);
        int numPro = num1 * num2;
        System.out.println("num1 * num2 is " + numPro);
        int numQuo = num1 / num2;
        System.out.println("num1 / num2 is " + numQuo);
        int numMod = num1 % num2;
        System.out.println("num1 % num2 is " + numMod);


        /* 
        When an expression involves two values of different types,
        the higher-precision type is used as the result.
        The less precise value is "up-cast" or COERCED into the higher-precision.
        */
        double pi = 3.14159;
        double twoPi = pi * 2;
        System.out.println("pi is " + pi);
        System.out.println("pi * 2 is " + twoPi);
        // pi is of type double; 2 is of type int
        // 2 is coerced to a double, and the product is evaluated as a double.

        /*
        * WARNING!!!
        * Integer division in Java by default drops remainders, like Python's
        * two-slash (//) operator.
        * Floating-point division is like Python.
        */
        int x = 17/3; // what is x?
        System.out.println("x is " + x);
        int y = 17 % 3; // what is y?
        System.out.println("y is " + y);

        // We can convert from on type to another with a "cast", similar to 
        // converting in Python with functions like float() or int().
        double z = (double)x / y; // what is z?
        System.out.println("z is " + z);



        // W13-2 (second part of lab)
        Scanner input = new Scanner(System.in);

        System.out.println("enter a byte: ");
        byte byteNum = input.nextByte();
        double squareByte = Math.pow(byteNum, 2);
        System.out.println("byteNum is " + byteNum + " and it is type byte and its square is " + squareByte);

        System.out.println("enter a short:");
        short shortNum = input.nextShort();
        double squareShort = Math.pow(shortNum, 2);
        System.out.println("shortNum is " + shortNum + " and it is type short and its square is " + squareShort);

        System.out.println("enter an int:");
        int intNum = input.nextInt();
        double squareInt = Math.pow(intNum, 2);
        System.out.println("intNum is " + intNum + " and it is type int and its square is " + squareInt);

        System.out.println("enter a Long:");
        long longNum = input.nextLong();
        double squareLong = Math.pow(longNum, 2);
        System.out.println("longNum is " + longNum + " and it is type long and its square is " + squareLong);

        System.out.println("enter a float:");
        float floatNum = input.nextFloat();
        double squareFloat = Math.pow(floatNum, 2);
        System.out.println("floatNum is " + floatNum + " and it is type float and its square is " + squareFloat);

        System.out.println("enter a double:");
        double doubleNum = input.nextDouble();
        double squareDouble = Math.pow(doubleNum, 2);
        System.out.println("doubleNum is " + doubleNum + " and it is type double and its square is " + squareDouble);

        System.out.println("enter a boolean:");
        boolean booleanVal = input.nextBoolean();
        System.out.println("booleanVal is " + booleanVal + " and it is type boolean");

        System.out.println("enter a char:");
        char charVal = input.next().charAt(0);
        System.out.println("charVal is " + charVal + " and it is type char");
    }
}