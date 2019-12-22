package comm;

public class Simulator {
	
	void playSound(Animal a)
	{
		System.out.println("��������: "+a.getAnimalName());
		a.cry();
	}
	
	public static void main(String[] args) {
		Simulator sim = new Simulator();
		Dog d = new Dog();
		Cat c = new Cat();
		sim.playSound(d);
		sim.playSound(c);
	}

}
