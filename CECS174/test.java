import java.util.Scanner;
public class test {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        double dnum = 5; //line 1
        int num1 = scan.nextInt();
        int num2 = scan.nextInt();
        System.out.println(num1 + num2); //line 2
        System.out.println(num1 + num2/2); //lin3
        num1 = num2 = 0; //line4
        dnum = num1 + num2; //line5
        System.out.println(num1 / num2); //line 6

    }
}
