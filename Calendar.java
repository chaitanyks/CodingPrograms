import java.util.Scanner;

public class Calendar {

    public static void main(String[] args) {
	// write your code here
        int n;
        System.out.print("Enter the Date: ");
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();

        if(n>=11&n<=13)
        {
            System.out.println(n+"th");
        }
        else
        {
            switch (n%10){
                case 1:
                    System.out.println(n+"st");
                    break;
                case 2:
                    System.out.println(n+"nd");
                    break;
                case 3:
                    System.out.println(n+"rd");
                    break;
                default:
                    System.out.println(n+"th");
            }
        }
    }
}
