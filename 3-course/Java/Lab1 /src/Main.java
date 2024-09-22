import java.util.Scanner;

public class Main {
    private static final Scanner input = new Scanner(System.in);
    public static void main(String[] args) {
        System.out.println("Выбери номер задания\n1)Сиракузская последовательность\n" +
                "2)Сумма ряда\n3)Ищем клад\n4)Логистический максимин\n5)Дважды четное число");
        int a = input.nextInt();
        switch (a){
            case 1:
                collatz();
                break;
            case 2:
                several();
                break;
            case 3:
                clad();
                break;
            case 4:
                truck();
                break;
            case 5:
                doubleParity();
                break;
        }
    }
    static void collatz(){
        System.out.println("Введите натуральное число");
        int n;
        n = input.nextInt();

        int counter = 0;
        while (n!=1) {
            if (n % 2 == 0) {
                n = n / 2;
            } else {
                n = 3 * n + 1;
            }
            counter++;
        }
        System.out.println("Количество шагов "+ (counter));
    }

    static void several(){
        System.out.println("Введите натуральное число");
        int n;
        n = input.nextInt();
        int summa = 0;
        for (int i = 0; i<n; i++){
            if (i%2==0){
                summa+=input.nextInt();
            }
            else{
                summa -= input.nextInt();
            }

        }
        System.out.println(summa);

    }

    static void clad(){
        int currentX = 0;
        int currentY = 0;
        System.out.println("Координаты клада:");
        int x = input.nextInt();
        int y = input.nextInt();
        int count = 0;
        int minCount = 0;
        String direction = "";
        while (!direction.equals("стоп")) {
            direction = input.next();
            if ((currentX == x) && (currentY == y)){
                minCount = count;
            }
            else {
                switch (direction) {
                    case "север":
                        currentY += input.nextInt();
                        count += 1;
                        break;
                    case "юг":
                        currentY -= input.nextInt();
                        count += 1;
                        break;
                    case "запад":
                        currentX -= input.nextInt();
                        count += 1;
                        break;
                    case "восток":
                        currentX += input.nextInt();
                        count += 1;
                        break;
                }
            }
        }
        System.out.println(minCount);
    }


    static void truck(){
        System.out.println("Введите количество дорог");
        int count_road = input.nextInt();
        int maximum = 0;
        int road = 1;
        for (int i=0; i<count_road; i++){
            System.out.println("Введите количество тунелей");
            int count_tunnel = input.nextInt();
            int minimum = 10000000;
            for (int j = 0; j < count_tunnel; j++){
                System.out.println("Введите высоту тунелей");
                int height = input.nextInt();
                if (minimum>height){
                    minimum = height;
                }
            }
            if (maximum < minimum){
                maximum = minimum;
                road = i+1;
            }
        }
        System.out.println("Номер дороги " + road + " и высота " + maximum);
    }

    static void doubleParity(){
        System.out.println("Введите трехзначное положительное число");
        int number = input.nextInt();
        int summa = 0;
        int multiplication = 1;
        while (number>0){
            summa += number%10;
            multiplication = multiplication * number%10;
            number/=10;
        }
        if (summa == multiplication){
            System.out.println("Дважды четное число");
        }
        else {
            System.out.println("Не дважды четное число");
        }
    }
}