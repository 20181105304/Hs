package com;

public class B extends P{
	
	String group;
	
	B(){
		super();
	}
	B(String name,String age,String sex,String height){
		super(name, age, sex, height);
	}
	
	public String getGroup() {
		return group;
	}
	public void setGroup(String group) {
		this.group = group;
	}
	void dancing(){
		System.out.println("����B���dancing����");
	}
	@Override
	void eat() {
		// TODO Auto-generated method stub
		System.out.println("����P�ṩ��eat��������ʱ��B���е�ʵ��");
	}
}
