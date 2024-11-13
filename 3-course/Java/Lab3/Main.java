import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        Board board = new Board();
        board.init();
        board.setColorGame('w');

        System.out.println();

        boolean isGame = true;
        Scanner in = new Scanner(System.in);


        while (isGame){
            board.print_board();
            System.out.println();

            System.out.println("Управление:");
            System.out.println("----row ol row1 col1: Ход фигуры из клетки (row, col) в (row1, col1)");

            System.out.println("Взятые Белые:"+board.getTakeWhite().toString());
            System.out.println("Взятые Черные:"+board.getTakeBlack().toString());

            //check
            String loser;
            if (board.isCheck(board.getColorGame())){
                if (board.getColorGame() == 'w'){
                    loser = "БЕЛЫЕ";
                }
                else {
                    loser = "ЧЕРНЫЕ";
                }
                if (board.isCheckmate(board.getColorGame())){
                    System.out.println("ШАХ И МАТ!!! Игра закончена");
                    System.out.println( loser+" ПРОИГРАЛИ!");
                    break;
                }
                else {
                    System.out.println("ШАХ!!! Ваш король под шахом! Сделайте ход, чтобы избежать шаха.");

                }
            }

            switch (board.getColorGame()){
                case 'w': System.out.println("Ход белых"); break;
                case 'b': System.out.println("Ход черных"); break;
            }

            System.out.print("Введите ход: ");

            String inputLine = in.nextLine();
            int row, col, row1, col1;
            String [] coords = inputLine.split(" ");
            row = Integer.parseInt(coords[0]);
            col = Integer.parseInt(coords[1]);
            row1 = Integer.parseInt(coords[2]);
            col1 = Integer.parseInt(coords[3]);

            if (board.isCheckmate(board.getColorGame())){
                System.out.println("ШАХ И МАТ!!! Игра закончена");
                break;
            }

            while (!board.move_figure(row, col, row1, col1)){
                System.out.println("Ошибка! Повторите ход фигуры!");
                System.out.print("Введите ход: ");
                inputLine = in.nextLine();
                coords = inputLine.split(" ");
                row = Integer.parseInt(coords[0]);
                col = Integer.parseInt(coords[1]);
                row1 = Integer.parseInt(coords[2]);
                col1 = Integer.parseInt(coords[3]);
            }

            switch (board.getColorGame()){
                case 'w': board.setColorGame('b');break;
                case 'b': board.setColorGame('w');break;
            }
        }

    }
}