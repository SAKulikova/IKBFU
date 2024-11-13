import Figures.Bishop;
import Figures.Figure;
import Figures.King;
import Figures.Knight;
import Figures.Pawn;
import Figures.Queen;
import Figures.Rook;
import java.util.ArrayList;
import java.util.Scanner;

public class Board {
    private Figure  fields[][] = new Figure[8][8];
    private ArrayList<String> takeWhite = new ArrayList(16);
    private ArrayList<String> takeBlack = new ArrayList(16);

    Scanner in = new Scanner(System.in);

    private char colorGame;

    public void setColorGame(char colorGame) {
        this.colorGame = colorGame;
    }

    public char getColorGame() {
        return colorGame;
    }


    public void init(){
        this.fields[0] = new Figure[]{
                new Rook("R", 'w'), new Knight("N", 'w'),
                new Bishop("B", 'w'), new Queen("Q", 'w'),
                new King("K", 'w'), new Bishop("B", 'w'),
                new Knight("N", 'w'),new Rook("R", 'w')
        };
        this.fields[1] = new Figure[]{
                new Pawn("P", 'w'),    new Pawn("P", 'w'),
                new Pawn("P", 'w'),    new Pawn("P", 'w'),
                new Pawn("P", 'w'),    new Pawn("P", 'w'),
                new Pawn("P", 'w'),    new Pawn("P", 'w'),
        };

        this.fields[7] = new Figure[]{
                new Rook("R", 'b'), new Knight("N", 'b'),
                new Bishop("B", 'b'), new Queen("Q", 'b'),
                new King("K", 'b'), new Bishop("B", 'b'),
                new Knight("N", 'b'),new Rook("R", 'b')
        };
        this.fields[6] = new Figure[]{
                new Pawn("P", 'b'),    new Pawn("P", 'b'),
                new Pawn("P", 'b'),    new Pawn("P", 'b'),
                new Pawn("P", 'b'),    new Pawn("P", 'b'),
                new Pawn("P", 'b'),    new Pawn("P", 'b'),
        };
    }

    public String getCell(int row, int col){
        Figure figure = this.fields[row][col];
        if (figure == null){
            return "    ";
        }
        return " "+figure.getColor()+figure.getName()+" ";
    }

    public ArrayList<String> getTakeWhite() {
        return takeWhite;
    }

    public ArrayList<String> getTakeBlack() {
        return takeBlack;
    }


    public boolean barrierOnBoard(int row, int col, int row1, int col1){

        Figure figure = fields[row][col];
        if (figure  instanceof Knight) {
            return false;
        }

        int rowDirection = Integer.signum(row1-row);
        int colDirection = Integer.signum(col1 - col);

        int currentRow = row+rowDirection;
        int currentCol = col + colDirection;

        while (currentRow != row1 || currentCol != col1){
            if (fields[currentRow][currentCol] != null){
                return true;
            }

            currentRow += rowDirection;
            currentCol += colDirection;
        }

        return false;
    }

    public boolean isCheck(char color){
        int kingRow = -1;
        int kingCol = -1;
        for (int row = 0; row<8; row++){
            for (int col = 0; col<8; col++){
                Figure figure = fields[row][col];
                if (figure != null && figure instanceof King && figure.getColor()==color){
                    kingRow = row;
                    kingCol = col;
                    break;
                }
            }
        }

        //Проверяю все фигуры противника, могут ли они атаковать короля
        for (int row = 0; row<8; row++){
            for(int col = 0; col<8; col++){
                Figure figure = fields[row][col];
                if (figure != null && figure.getColor() != color){
                    if (figure.canAttack(row, col, kingRow, kingCol) && !barrierOnBoard(row, col, kingRow, kingCol)){
                        return true;
                    }
                }
            }
        }

        return false;
    }

    public boolean isCheckmate(char color){ //если стоит мат и королю никак не избежать мата
        if (!isCheck(this.colorGame)){
            for (int row = 0; row<8; row++){
                for (int col = 0; col < 8; col++){
                    Figure figure = this.fields[row][col];
                    if (figure != null && figure.getColor() == color){
                        for(int NewRow = 0; NewRow<8; NewRow++){
                            for(int NewCol = 0; NewCol<8; NewCol++){
                                Figure capturedFigure = fields[NewRow][NewCol];
                                fields[NewRow][NewCol] = figure;
                                fields[row][col] = null;
                                boolean notIsCheck = isCheck(this.colorGame);
                                fields[row][col] = figure;
                                fields[NewRow][NewCol] = capturedFigure;
                                if (notIsCheck){
                                    return false;
                                }
                            }
                        }
                    }
                }
            }
        }
        return true;
    }

    public void promotion( int row1, int col1){

        System.out.println("Вы дошли до противоположного конца. Вы можете выбрать любую фигуру:" +
                "R - ладья\n" +
                "N - конь\n" +
                "B - слон\n" +
                "Q - королева\n");
        System.out.println("Для того, чтобы выбрать фигуру нужно ввести заглавную букву");
        char choice = in.nextLine().charAt(0);

        switch (choice){
            case 'R':
                this.fields[row1][col1] = new Rook("R", this.colorGame);
                break;
            case 'N':
                this.fields[row1][col1] = new Knight("N", this.colorGame);
                break;
            case 'B':
                this.fields[row1][col1] = new Bishop("B", this.colorGame);
                break;
            case 'Q':

                this.fields[row1][col1] = new Queen("Q", this.colorGame);
                break;
            default:
                System.out.println("По умолчания Q");
                this.fields[row1][col1] = new Queen("Q", this.colorGame);
                break;
        }


    }

    public boolean move_figure(int row, int col, int row1, int col1 ){

        Figure figure =  this.fields[row][col];



        if (figure == null || figure.getColor() != this.colorGame) {
            return false;
        }

        if ((figure  instanceof Pawn) && (row1 == 7 || row1 == 0)){
            promotion(row1, col1);
            this.fields[row][col] = null;
            return true;
        }

        if (figure.canMove(row, col, row1, col1) && !barrierOnBoard(row, col, row1, col1) && this.fields[row1][col1] == null) {
            System.out.println("move");
            this.fields[row1][col1] = figure;
            this.fields[row][col] = null;
            return true;
        }
        if (figure.canAttack(row, col, row1, col1) && this.fields[row1][col1] != null
                && this.fields[row1][col1].getColor() != this.fields[row][col].getColor()) {
            System.out.println("attack: " + this.fields[row1][col1].getColor() + this.fields[row1][col1].getName());

            switch (this.fields[row1][col1].getColor()) {
                case 'w':
                    this.takeWhite.add(this.fields[row1][col1].getColor() + this.fields[row1][col1].getName());
                    break;
                case 'b':
                    this.takeBlack.add(this.fields[row1][col1].getColor() + this.fields[row1][col1].getName());
                    break;
            }
            this.fields[row1][col1] = figure;
            this.fields[row][col] = null;
            return true;
        }

        return false;
    }

    public void print_board(){
        System.out.println(" +----+----+----+----+----+----+----+----+");
        for(int row = 7; row > -1; row--){
            System.out.print(row);
            for(int col = 0; col< 8; col++){
                System.out.print("|"+getCell(row, col));
            }
            System.out.println("|");
            System.out.println(" +----+----+----+----+----+----+----+----+");
        }

        for(int col = 0; col < 8; col++){
            System.out.print("    "+col);
        }
    }


}