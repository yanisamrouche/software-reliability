import java.util.*;

/**
 *
 * Cette classe n'est pas documentée
 * Le constructeur prend un tableau de chaines
 * de caractère et fait des opérations sur ce tableau
 * en lien avec du tri et de l'elimination de doublon
 * @version unknown
 * @author web 
 *
 */
public class StringArray {

	private final String [] mlist;

	public StringArray(String[] list){
		int dupl = 0;
		if (list.length > 0) {
			String last = list[0];
			int index = 0;
			while (++index < list.length){
				String comp = list[index];
				int diff = last.compareTo(comp);
				if (diff > 0){
					Arrays.sort(list);
					last=list[index];
				} else if (diff < 0) {
					last = comp;
				}
			}
		}
		mlist = getArrayWithOutDuplicatedValues(list);
	}
	
	public  String [] getMlist() {
		return mlist;
	}

	public String getString(int index){
		return mlist[index];
	}

	public int IndexOf( String value){
		int base = 0;
		int limit = mlist.length -1;
		while (base <= limit){
			int cur = (base + limit) >> 1;
		int diff = value.compareTo(mlist[cur]);
			System.out.println("#### "+diff);
		if (diff < 0){
			System.out.println("if");
			limit = cur - 1;
		} else if (diff > 0) {
			System.out.println("else-if");
			base = cur + 1;
		} else {
			System.out.println("else");
			return cur;
		}
		}
		System.out.println("out of while");
		return -1;
	}

	public int size(){
		return mlist.length;
	}

	public String[] getArrayWithOutDuplicatedValues(String[] l){
		int dupl = 0;
		List<String> copy = new ArrayList<String>(Arrays.asList(l));

		for (int i=0; i<copy.size(); i++){
			String string = copy.get(i);
			for(int k=0; k<copy.size(); k++){
				if(string.equals(copy.get(k)) && i!=k){
					dupl++;
					copy.remove(k);
				}
			}
		}
		String[] array = copy.toArray(new String[0]);
		return array;


	}


}
