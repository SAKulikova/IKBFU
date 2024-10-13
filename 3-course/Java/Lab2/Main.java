import java.util.Arrays;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Main {
    private static final Scanner scan = new Scanner(System.in);
    public static void main(String[] args) {
        System.out.println("Выбери номер задания:\n" +
                "1)Найти наибольшую подстроку без повторяющихся символов\n" +
                "2)Объединить два отсортированных массива\n" +
                "3)Найти максимальную сумму подмассива\n" +
                "4)Повернуть массив на 90 градусов по часовой стрелке\n" +
                "5)Найти пару элементов в массиве, сумма которых равна заданному числу\n"+
                "6)Найти сумму всех элементов в двумерном массиве\n"+
                "7)Найти максимальный элемент в каждой строке двумерного массива\n" +
                "8)Повернуть двумерный массив на 90 градусов против часовой стрелке\n"
        );
        int a = scan.nextInt();
        switch (a){
            case 1:
                substring();
                break;
            case 2:
                twoSorted();
                break;
            case 3:
                maxSumSubarrays();
                break;
            case 4:
                clockwise();
                break;
            case 5:
                pairOfElements();
                break;
            case 6:
                sumOfArrays();
                break;
            case 7:
                maxRow();
                break;
            case 8:
                counterclockwise();
                break;
        }
    }
    static void substring(){
        System.out.println("Введите строку");
        String s = scan.next();
        Set<Character> uniqueChars = new HashSet<>();
        int maxLength = 0;
        int start = 0;
        int longestStart = 0;

        for (int end = 0; end < s.length(); end++) {
            char currentChar = s.charAt(end);
            while (uniqueChars.contains(currentChar)) {
                uniqueChars.remove(s.charAt(start));
                start++;
            }
            uniqueChars.add(currentChar);

            if (end - start + 1 > maxLength) {
                maxLength = end - start + 1;
                longestStart = start;
            }
        }
        System.out.println(s.substring(longestStart, longestStart + maxLength));

    }
    static void twoSorted(){
        int [] one = new int[5];
        System.out.println("Введите первый отсортированный массив длиной 5 чисел");
        for (int i=0; i< 5; i++){
            one[i] = scan.nextInt();
        }
        int[] two = new int[5];
        System.out.println("Введите второй отсортированный массив длиной 5 чисел");
        for (int j =0; j<5; j++){
            two[j] = scan.nextInt();
        }
        int[] a = new int[10];
        for (int i = 0; i<5; i++){
            a[i] = one[i];
            a[5+i] = two[i];
        }
        Arrays.sort(a);
        for (int i:a){
            System.out.print(i + " ");
        }

    }
    static void maxSumSubarrays(){
        System.out.println("Введите количество чисел");
        int n = scan.nextInt();
        int [] arrays = new int[n];
        System.out.println("Введите массив чисел");
        for (int i = 0; i<n; i++){
            arrays[i] = scan.nextInt();
        }
        int currentSum = 0;
        int maxSum = arrays[0];;
        for(int i = 0; i<n; i++){
            currentSum += arrays[i];
            maxSum = Math.max(maxSum, currentSum);
            currentSum = Math.max(currentSum,0);
        }
        System.out.println(maxSum);
    }
    static void clockwise(){
        System.out.println("Введите кол-во строк");
        int row = scan.nextInt();
        System.out.println("Введите кол-во столбцов");
        int col = scan.nextInt();
        System.out.println("Введите матрицу");
        int [][] a = new int[row][col];
        for (int i = 0; i<row;  i++){
            for (int j = 0; j < col; j++){
                a[i][j] = scan.nextInt();
            }
        }
        int [][] array = new int[col][row];
        System.out.println("Поворот на 90 по часовой");
        for (int i = 0; i < col; i++){
            for (int j = 0; j < row; j++){
                array[i][j] = a[row - 1 - j][i];
                System.out.print(" " + array[i][j] + " ");
            }
            System.out.println();
        }
    }
    static void pairOfElements(){
        System.out.println("Введите количество чисел в массиве");
        int count = scan.nextInt();
        int [] elements = new int[count];
        System.out.println("Введите массив");
        for (int i=0; i<count; i++){
            elements[i] = scan.nextInt();
        }
        System.out.println("Введите target");
        int target = scan.nextInt();
        boolean flag = false;
        for (int i = 0; i<count+1; i++){
            for (int j = i +1; j< count; j++){
                if (elements[i]+elements[j] == target){
                    System.out.println(elements[i] + " " + elements[j]);
                    flag = true;
                }
            }
        }
        if (!flag){
            System.out.println("null");
        }
    }
    static void sumOfArrays(){
        int sum = 0;
        System.out.println("Введите кол-во строк");
        int row = scan.nextInt();
        System.out.println("Введите кол-во столбцов");
        int col = scan.nextInt();
        System.out.println("Введите матрицу");
        int [][] arrays = new int[row][col];
        for (int i = 0; i<row;  i++){
            for (int j = 0; j < col; j++){
                arrays[i][j] = scan.nextInt();
                sum += arrays[i][j];
            }
        }
        System.out.println(sum);
    }
    static void maxRow(){
        System.out.println("Введите кол-во строк");
        int row = scan.nextInt();
        System.out.println("Введите кол-во столбцов");
        int col = scan.nextInt();
        System.out.println("Введите матрицу");
        int [][] arrays = new int[row][col];
        for (int i = 0; i<row;  i++){
            for (int j = 0; j < col; j++){
                arrays[i][j] = scan.nextInt();
            }
        }
        int [] maxElemens = new int[row];
        for (int i =0; i< row; i++){
            int max = 0;
            for (int j =0; j<col; j++){
                if (arrays[i][j] > max){
                    max = arrays[i][j];
                }
                maxElemens[i] = max;
            }
        }
        for (int maxElemen : maxElemens) {
            System.out.print(maxElemen + " ");
        }
    }
    static void counterclockwise(){
        System.out.println("Введите кол-во строк");
        int row = scan.nextInt();
        System.out.println("Введите кол-во столбцов");
        int col = scan.nextInt();
        System.out.println("Введите матрицу");
        int [][] a = new int[row][col];
        for (int i = 0; i<row;  i++){
            for (int j = 0; j < col; j++){
                a[i][j] = scan.nextInt();
            }
        }
        int[][] a2 = new int[col][row];
        for (int i = 0; i< col; i++){
            for(int j =0; j< row; j++){
                a2[i][j] = a[j][col - i -1];
                System.out.print(a2[i][j] + " ");
            }
            System.out.println(" ");
        }

    }


}