package com;

public class Test {
	public static void main(String[] args) {
		P a = new A("zhangsan ","lisi ","wangwu ","zhaoliu ");
		a.eat();
		
		System.out.println(a.getAge()+a.getHeight()+a.getName()+a.getSex());
		P b = new B("zhangsan ","lisi ","wangwu ","zhaoliu ");
		b.eat();
		System.out.println(b.getAge()+b.getHeight()+b.getName()+b.getSex());
//		A aa = new A("zhangsan ","lisi ","wangwu ","zhaoliu ");
//		aa.eat();
//		aa.run();
	}

}
