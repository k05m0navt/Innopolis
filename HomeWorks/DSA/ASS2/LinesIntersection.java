import java.lang.Math;

public class LinesIntersection
{
    public static void main(String[] args) {
        double      xA;
        double      yA;
        double      xB;
        double      yB;
        double      xC;
        double      yC;
        double      xD;
        double      yD;
        double[]    point_P;

        xA = 0;
        yA = 0;
        xB = 0;
        yB = 1;
        xC = 1;
        yC = 0;
        xD = 1;
        yD = 1;
        point_P = checkIntersection(xA, yA, xB, yB, xC, yC, xD, yD); 
        if (point_P[0] == Double.MAX_VALUE && point_P[1] == Double.MAX_VALUE)
            System.out.println("Do not intersects");
        else
        {
            System.out.println(point_P[0]);
            System.out.print(point_P[1]);
        }
        
    }

    private static double[] checkIntersection(double xA, double yA, double xB, double yB, double xC, double yC, double xD, double yD)
    {
        double  denumenator;
        boolean checkBelongs_AB;
        boolean checkBelongs_CD;
        double  xP;
        double  yP;
        double[]  answer = {Double.MAX_VALUE, Double.MAX_VALUE};

        denumenator = (xA - xB) * (yC - yD) - (yA - yB) * (xC - xD);
        if (denumenator == 0)
            return (answer);
        xP = ((xA * yB - yA*xB) * (xC - xD) - (xA - xB) * (xC * yD - yC * xD)) / denumenator;
        yP = ((xA * yB - yA*xB) * (yC - yD) - (yA - yB) * (xC * yD - yC * xD)) / denumenator;
        checkBelongs_AB = checkBelonging(xA, yA, xB, yB, xP, yP);
        checkBelongs_CD = checkBelonging(xC, yC, xD, yD, xP, yP);
        if (!(checkBelongs_AB && checkBelongs_CD))
            return (answer);
        answer[0] = xP;
        answer[1] = yP;
        return (answer);
    }

    private static boolean checkBelonging(double x1, double y1, double x2, double y2, double xP, double yP)
    {
        double min_X;
        double max_X;
        double min_Y;
        double max_Y;
        boolean belongs_to_x;
        boolean belongs_to_y;
        boolean answer;

        min_X = Math.min(x1, x2);
        max_X = Math.max(x1, x2);
        min_Y = Math.min(y1, y2);
        max_Y = Math.max(y1, y2);
        belongs_to_x = (min_X <= xP) && (xP <= max_X);
        belongs_to_y = (min_Y <= yP) && (yP <= max_Y);
        answer = belongs_to_x && belongs_to_y; 
        return (answer);
    }
}