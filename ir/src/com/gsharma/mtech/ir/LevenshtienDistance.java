package com.gsharma.mtech.ir;

public class LevenshtienDistance {

    private int[][] getDistance(String s1, String s2)
    {
        int[][] result = new int[s1.length() + 1][s2.length() + 1];
        for(int i = 0; i <= s1.length(); i++)
            result[i][0] = i;
        for(int j = 0; j <= s2.length(); j++)
            result[0][j] = j;

        for(int i = 1; i < s1.length() + 1; i++)
        {
            for(int j = 1; j < s2.length() + 1; j++)
            {
                if(s1.charAt(i - 1) == s2.charAt(j - 1))
                {
                    result[i][j] = Math.min(result[i-1][j] + 1, Math.min(result[i][j-1] + 1, result[i-1][j-1]));
                }
                else
                {
                    result[i][j] = Math.min(result[i-1][j] + 1, Math.min(result[i][j-1] + 1, result[i-1][j-1] + 1));
                }
            //    printResult(s1, s2, result);
            }
        }
        return result;
    }

    private void printResult(String s1, String s2, int[][] result)
    {
        boolean prints1 = true;
        for(int i = 0; i < s1.length() + 1; i++)
        {
            if(prints1)
            {
                System.out.print("\t\t");
                for(int k = 0; k < s1.length(); k++)
                    System.out.print(s1.charAt(k) + "\t");
                System.out.println("");
                prints1 = false;
            }
            if(i > 0)
                System.out.print(s2.charAt(i - 1));
            System.out.print("\t");
            for (int j = 0; j < s2.length() + 1; j++)
            {
                System.out.print(result[i][j]);
                System.out.print("\t");
            }
            System.out.println("");
        }
    }


    public static void main(String[] args) {
        String s1 = "cat", s2 = "fat";
        LevenshtienDistance obj = new LevenshtienDistance();
	    int[][] result = obj.getDistance(s1, s2);
	    obj.printResult(s1, s2, result);
    }
}
