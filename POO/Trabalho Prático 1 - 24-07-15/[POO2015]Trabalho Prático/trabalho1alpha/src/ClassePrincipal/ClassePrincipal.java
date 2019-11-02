package ClassePrincipal;

import Interface.Principal;




public class ClassePrincipal {
    public static void main(String[] args){
        Principal janelaPrincipal = new Principal();
        janelaPrincipal.setVisible(true);
        janelaPrincipal.toFront();
    }
   
}
