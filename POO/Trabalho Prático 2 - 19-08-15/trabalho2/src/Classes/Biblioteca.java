/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package Classes;


public class Biblioteca {
    private static Configuracao config = new Configuracao();
    
   public Configuracao getConfig(){
       return config;
   }
   
   public void setConfig(Configuracao config){
       this.config = config;
   }
   
   
}
