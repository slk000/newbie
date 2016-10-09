import java.util.*;
import java.util.regex.*;
public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        while(in.hasNext()) {
            int T = in.nextInt();
            in.nextLine();
            String pattern = "^[a-z|_]\\w{0,19}$";
            Pattern r = Pattern.compile(pattern);
            Boolean res=true;
            Map<String, Boolean> map = new HashMap<String, Boolean>();
            for (int i = 0; i < T; i++){
                
                String line = in.nextLine();

                Matcher m = r.matcher(line);
                if (m.find( )) {
                    //System.out.println("Found value: " + m.group(0) );
                    if (map.containsKey(line)){
                        //System.out.println("Found");
                        res &= false;
                    }
                    else{
                        map.put(line,true);
                    }
                } else {
                    res &= false;
                    //break;
                }
            }
            if (res){
                System.out.println("Resonable!");
            }
            else{
                System.out.println("UnResonable!");
            }
        }
    }
}