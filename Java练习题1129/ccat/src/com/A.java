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
		System.out.println("����A���run����");
	}
	@Override
	void eat() {
		// TODO Auto-generated method stub
		System.out.println("����P�ṩ��eat��������ʱ��A���е�ʵ��");
	}

}
