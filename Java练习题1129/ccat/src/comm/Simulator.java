package comm;

public class Simulator {
	
	void playSound(Animal a)
	{
		System.out.println("动物种类: "+a.getAnimalName());
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
