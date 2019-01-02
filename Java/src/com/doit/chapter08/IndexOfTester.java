package com.doit.chapter08;

import java.util.Scanner;

public class IndexOfTester {
    public static void main(String[] args) {
        Scanner stdIn = new Scanner(System.in);

        System.out.print("텍스트 : ");
        String s1 = stdIn.next();

        System.out.print("패턴 : ");
        String s2 = stdIn.next();

        int index1 = s1.indexOf(s2);
        int index2 = s1.lastIndexOf(s2);

        if (index1 == -1)
            System.out.println("텍스트 안에 패턴이 없음");
        else {
            int len1 = 0;
            for (int i = 0; i < index1; i++)
                len1 += s1.substring(i, i + 1).getBytes().length;
            len1 += s2.length();

            int len2 = 0;
            for (int i = 0; i < index2; i++)
                len2 += s1.substring(i, i + 1).getBytes().length;
            len2 += s2.length();

            System.out.println("텍스트 : " + s1);
            System.out.printf(String.format("패턴 : %%%ds\n", len1), s2);
            System.out.println("텍스트 : " + s1);
            System.out.printf(String.format("패턴 : %%%ds\n", len2), s2);
        }
    }
}
