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
		System.out.println("我是B类的dancing方法");
	}
	@Override
	void eat() {
		// TODO Auto-generated method stub
		System.out.println("我是P提供的eat方法，此时在B类中的实现");
	}
}
