package com;

public class A extends P{
	
	String play;
	
	A(){
		super();
	}
	A(String name,String age,String sex,String height){
		super(name, age, sex, height);
	}
	
	public String getPlay() {
		return play;
	}
	public void setPlay(String play) {
		this.play = play;
	}
	void run(){
		System.out.println("我是A类的run方法");
	}
	@Override
	void eat() {
		// TODO Auto-generated method stub
		System.out.println("我是P提供的eat方法，此时在A类中的实现");
	}

}
