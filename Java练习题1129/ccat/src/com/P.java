package com;

public abstract class P {

	private String name;
	private String age;
	private String sex;
	private String height;
	P(){}
	P(String name,String age,String sex,String height){
		this.name = name;
		this.age = age;
		this.sex = sex;
		this.height = height;
	}
	
	
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	public String getAge() {
		return age;
	}
	public void setAge(String age) {
		this.age = age;
	}
	public String getSex() {
		return sex;
	}
	public void setSex(String sex) {
		this.sex = sex;
	}
	public String getHeight() {
		return height;
	}
	public void setHeight(String height) {
		this.height = height;
	}
	abstract void eat();
}
