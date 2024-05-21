// import scanner class 
import java.util.Scanner;

public class FortuneTeller {
    public static void main(String[] args) {
        // identify scanner
        Scanner input = new Scanner(System.in);

        // condition for valid input 
        boolean validEntry = true;

        // get integer for expression
        System.out.println("Enter an integer (1-10):");
        int expression = input.nextInt();

        // get character for object
        System.out.println("Enter a letter (A-I):");
        char object = input.next().charAt(0);

        //get integer for animal 
        System.out.println("Enter another integer (1-11):");
        int animal = input.nextInt();

        // placeholders for the string used in the final print statment
        String expressionSymbol = "";
        String expressionWords = "";
        String objectSymbol = "";
        String objectWords = "";
        String animalSymbol = "";
        String animalWords = "";

        // if statements checking through numbers 1-10 for respective expression symbol and phrase 
        if (expression == 1) {
            expressionSymbol = ":-J";
            expressionWords = "have tongue in cheek";
        }
        else if (expression == 2) {
            expressionSymbol = ":-&";
            expressionWords = "are tongue tied";
        }
        else if (expression == 3) {
            expressionSymbol = "=^_^=";
            expressionWords = "are blushing";
        }
        else if (expression == 4) {
            expressionSymbol = ":-o";
            expressionWords = "are alarmed";
        }
        else if (expression == 5) {
            expressionSymbol = "=-D";
            expressionWords = "are laughing out loud";
        }
        else if (expression == 6) {
            expressionSymbol = ">_<";
            expressionWords = "are angry";
        }
        else if (expression == 7) {
            expressionSymbol = "*_*";
            expressionWords = "are in love";
        }
        else if (expression == 8) {
            expressionSymbol = "(-_-)";
            expressionWords = "are bored";
        }
        else if (expression == 9) {
            expressionSymbol = ">_<*";
            expressionWords = "are annoyed";
        }
        else if (expression == 10) {
            expressionSymbol = "(*^_^*)";
            expressionWords = "are shy";
        }
        // if input is invalid, set validEntry to false 
        else {
            validEntry = false;
        }

        // if statements checking through numbers A-I for respective object symbol and phrase 
        if (object == 'A') {
            objectSymbol = "*<:)";
            objectWords = "wearing birthday hat";
        }
        else if (object == 'B') {
            objectSymbol = "0_";
            objectWords = "lying in bed";
        }
        else if (object == 'C') {
            objectSymbol = "@~)~~~~";
            objectWords = "picking a rose";
        }
        else if (object == 'D') {
            objectSymbol = "<•>";
            objectWords = "opening your eye";
        }
        else if (object == 'E') {
            objectSymbol = "-|–'";
            objectWords = "riding in an airplane";
        }
        else if (object == 'F') {
            objectSymbol = "*<<<<=";
            objectWords = "decorating a Christmas tree";
        }
        else if (object == 'G') {
            objectSymbol = "8[+]";
            objectWords = "giving a gift";
        }
        else if (object == 'H') {
            objectSymbol = "%%-";
            objectWords = "picking a four leaf clover";
        }
        else if (object == 'I') {
            objectSymbol = "(*)/(*)";
            objectWords = "riding a bicycle";
        }
        // if input is invalid, set validEntry to false 
        else {
            validEntry = false;
        }

        // if statements checking through numbers 1-11 for respective animal symbol and phrase 
        if (animal == 1) {
            animalSymbol = "(*V*)";
            animalWords = "a bird";
        }
        else if (animal == 2) {
            animalSymbol = "=^.^=";
            animalWords = "a cat";
        }
        else if (animal == 3) {
            animalSymbol = ":o3";
            animalWords = "a dog";
        }
        else if (animal == 4) {
            animalSymbol = "<><";
            animalWords = "a fish";
        }
        else if (animal == 5) {
            animalSymbol = "<:3)~";
            animalWords = "a mouse";
        }
        else if (animal == 6) {
            animalSymbol = "=8)";
            animalWords = "a pig";
        }
        else if (animal == 7) {
            animalSymbol = ":(III)-";
            animalWords = "a bee";
        }
        else if (animal == 8) {
            animalSymbol = "^o,o^";
            animalWords = "an owl";
        }
        else if (animal == 9) {
            animalSymbol = "( *)>";
            animalWords = "a penguin";
        }
        else if (animal == 10) {
            animalSymbol = "(‘.’)";
            animalWords = "a rabbit";
        }
        else if (animal == 11) {
            animalSymbol = "_@_v";
            animalWords = "a snail";
        }
        // if input is invalid, set validEntry to false 
        else {
            validEntry = false;
        }

        // checks if input is valid 
        if (validEntry == true) {
            // if input is valid, display corresponding symbols and phrases in separate print lines
            System.out.println("I see " + expressionSymbol + " " + objectSymbol + " " + animalSymbol);
            System.out.println("You " + expressionWords + " while you are " + objectWords + ", and you got " + animalWords + " as a gift.");
        }
        else {
            // if input is invalid, display error message 
            System.out.println("ERROR: invalid entry \nreturning money...");
        }
        
        double dnum = 5; //line 1
        int num1 = input.nextInt();
        int num2 = input.nextInt();
        System.out.println(num1 + num2); //line 2
        System.out.println(num1 + num2/2); //lin3
        num1 = num2 = 0; //line4
        dnum = num1 + num2; //line5
        System.out.println(dnum); //line 6
    }
}
