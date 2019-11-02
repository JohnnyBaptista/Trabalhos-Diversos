/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Interface;

import Controladores.ControladorClientes;
import Controladores.ControladorProdutos;
import Controladores.ControladorVendas;
import classes.Cartao;
import classes.Cheque;
import classes.Cliente;
import classes.Dinheiro;
import classes.Produto;
import classes.ProdutoNacional;
import classes.Venda;
import java.io.IOException;
import java.util.Calendar;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.DefaultComboBoxModel;
import javax.swing.JOptionPane;
import javax.swing.table.DefaultTableModel;

/**
 *
 * @author Eymar Lima
 */
public class CadastroDeVendas extends javax.swing.JDialog {
    private Venda novaVenda = new Venda(50);
    private Produto[] produtos;
    private DefaultTableModel dTM = new DefaultTableModel();
    private float valorTotal = 0;
    private Cliente[] listaClientes;
    
    public CadastroDeVendas(java.awt.Frame parent, boolean modal) throws IOException, ClassNotFoundException{
        super(parent, modal);
        initComponents();
        String[] header = {"Codigo do Produto","Descricão","Quantidade","Valor Individual"};
        ControladorProdutos control = new ControladorProdutos();
        produtos = control.lerProdutos();
        tabelaProdutos.setModel(dTM);
        dTM.setColumnIdentifiers(header);
    }

    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jScrollPane1 = new javax.swing.JScrollPane();
        jTable1 = new javax.swing.JTable();
        labelIcone = new javax.swing.JLabel();
        textFieldNumVenda = new javax.swing.JTextField();
        labelNumVenda = new javax.swing.JLabel();
        comboBoxCliente = new javax.swing.JComboBox();
        labelCliente = new javax.swing.JLabel();
        labelTipoPag = new javax.swing.JLabel();
        comboBoxTipoPag = new javax.swing.JComboBox();
        labelInformacoes = new javax.swing.JLabel();
        labelInfor1 = new javax.swing.JLabel();
        labelInfor2 = new javax.swing.JLabel();
        textFieldInfor1 = new javax.swing.JTextField();
        textFieldInfor2 = new javax.swing.JTextField();
        labelCodProd = new javax.swing.JLabel();
        labelQuantProd = new javax.swing.JLabel();
        textFieldQuantProd = new javax.swing.JTextField();
        textFieldCodProd = new javax.swing.JTextField();
        btnAdcionarItem = new javax.swing.JButton();
        jScrollPane2 = new javax.swing.JScrollPane();
        tabelaProdutos = new javax.swing.JTable();
        jLabel10 = new javax.swing.JLabel();
        jTextField6 = new javax.swing.JTextField();
        jButton2 = new javax.swing.JButton();
        jButton3 = new javax.swing.JButton();
        jLabel11 = new javax.swing.JLabel();

        jTable1.setModel(new javax.swing.table.DefaultTableModel(
            new Object [][] {
                {null, null, null, null},
                {null, null, null, null},
                {null, null, null, null},
                {null, null, null, null}
            },
            new String [] {
                "Title 1", "Title 2", "Title 3", "Title 4"
            }
        ));
        jScrollPane1.setViewportView(jTable1);

        setDefaultCloseOperation(javax.swing.WindowConstants.DISPOSE_ON_CLOSE);
        setTitle("Nova Venda");
        setResizable(false);
        addWindowListener(new java.awt.event.WindowAdapter() {
            public void windowOpened(java.awt.event.WindowEvent evt) {
                formWindowOpened(evt);
            }
        });

        labelIcone.setIcon(new javax.swing.ImageIcon(getClass().getResource("/Imagens/1436314180_shopping_basket red.png"))); // NOI18N

        textFieldNumVenda.setEditable(false);
        textFieldNumVenda.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                textFieldNumVendaActionPerformed(evt);
            }
        });

        labelNumVenda.setFont(new java.awt.Font("Tahoma", 0, 14)); // NOI18N
        labelNumVenda.setText("Número da Venda:");

        comboBoxCliente.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                comboBoxClienteActionPerformed(evt);
            }
        });

        labelCliente.setFont(new java.awt.Font("Tahoma", 0, 14)); // NOI18N
        labelCliente.setText("Cliente:");

        labelTipoPag.setFont(new java.awt.Font("Tahoma", 0, 14)); // NOI18N
        labelTipoPag.setText("Tipo de Pagamento");

        comboBoxTipoPag.setModel(new javax.swing.DefaultComboBoxModel(new String[] { "Dinheiro", "Cartão", "Cheque" }));
        comboBoxTipoPag.addFocusListener(new java.awt.event.FocusAdapter() {
            public void focusLost(java.awt.event.FocusEvent evt) {
                comboBoxTipoPagFocusLost(evt);
            }
        });

        labelInformacoes.setFont(new java.awt.Font("Tahoma", 0, 14)); // NOI18N
        labelInformacoes.setText("Informações:");

        labelInfor1.setFont(new java.awt.Font("Tahoma", 0, 14)); // NOI18N
        labelInfor1.setText("Nome:");

        labelInfor2.setFont(new java.awt.Font("Tahoma", 0, 14)); // NOI18N
        labelInfor2.setText("Número:");

        textFieldInfor1.setEnabled(false);

        textFieldInfor2.setEnabled(false);

        labelCodProd.setFont(new java.awt.Font("Tahoma", 0, 14)); // NOI18N
        labelCodProd.setText("Código do Produto:");

        labelQuantProd.setFont(new java.awt.Font("Tahoma", 0, 14)); // NOI18N
        labelQuantProd.setText("Quantidade:");

        textFieldQuantProd.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                textFieldQuantProdActionPerformed(evt);
            }
        });

        btnAdcionarItem.setIcon(new javax.swing.ImageIcon(getClass().getResource("/Imagens/1436315538_shopping-cart.png"))); // NOI18N
        btnAdcionarItem.setText("Adicionar Item");
        btnAdcionarItem.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnAdcionarItemActionPerformed(evt);
            }
        });

        tabelaProdutos.setFont(new java.awt.Font("Tahoma", 0, 14)); // NOI18N
        tabelaProdutos.setModel(new javax.swing.table.DefaultTableModel(
            new Object [][] {

            },
            new String [] {
                "Código do Produto", "Descrição", "Quantidade", "Valor Individual"
            }
        ) {
            boolean[] canEdit = new boolean [] {
                false, false, false, false
            };

            public boolean isCellEditable(int rowIndex, int columnIndex) {
                return canEdit [columnIndex];
            }
        });
        tabelaProdutos.setToolTipText("");
        jScrollPane2.setViewportView(tabelaProdutos);

        jLabel10.setFont(new java.awt.Font("Tahoma", 0, 14)); // NOI18N
        jLabel10.setIcon(new javax.swing.ImageIcon(getClass().getResource("/Imagens/1436315953_US-dollar.png"))); // NOI18N
        jLabel10.setText("Total a Pagar:");

        jTextField6.setEditable(false);
        jTextField6.setText("0");

        jButton2.setFont(new java.awt.Font("Tahoma", 0, 14)); // NOI18N
        jButton2.setIcon(new javax.swing.ImageIcon(getClass().getResource("/Imagens/1436243324_save.png"))); // NOI18N
        jButton2.setText("Salvar");
        jButton2.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton2ActionPerformed(evt);
            }
        });

        jButton3.setFont(new java.awt.Font("Tahoma", 0, 14)); // NOI18N
        jButton3.setIcon(new javax.swing.ImageIcon(getClass().getResource("/Imagens/1436243313_arrow-back.png"))); // NOI18N
        jButton3.setText("Voltar");
        jButton3.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton3ActionPerformed(evt);
            }
        });

        jLabel11.setFont(new java.awt.Font("Tahoma", 0, 24)); // NOI18N
        jLabel11.setText("Nova Venda");

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, layout.createSequentialGroup()
                        .addGap(0, 201, Short.MAX_VALUE)
                        .addComponent(jLabel10)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                        .addComponent(jTextField6, javax.swing.GroupLayout.PREFERRED_SIZE, 110, javax.swing.GroupLayout.PREFERRED_SIZE))
                    .addComponent(jScrollPane2, javax.swing.GroupLayout.PREFERRED_SIZE, 0, Short.MAX_VALUE)
                    .addGroup(layout.createSequentialGroup()
                        .addComponent(labelIcone)
                        .addGap(109, 109, 109)
                        .addComponent(jLabel11))
                    .addGroup(layout.createSequentialGroup()
                        .addGap(10, 10, 10)
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addGroup(layout.createSequentialGroup()
                                .addComponent(labelCliente)
                                .addGap(20, 20, 20)
                                .addComponent(comboBoxCliente, 0, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                            .addGroup(layout.createSequentialGroup()
                                .addComponent(labelInfor1, javax.swing.GroupLayout.PREFERRED_SIZE, 111, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addGap(18, 18, 18)
                                .addComponent(textFieldInfor1))
                            .addGroup(layout.createSequentialGroup()
                                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                    .addComponent(labelInfor2)
                                    .addComponent(labelQuantProd))
                                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                    .addGroup(layout.createSequentialGroup()
                                        .addGap(21, 21, 21)
                                        .addComponent(textFieldQuantProd, javax.swing.GroupLayout.PREFERRED_SIZE, 84, javax.swing.GroupLayout.PREFERRED_SIZE)
                                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                                        .addComponent(btnAdcionarItem)
                                        .addGap(0, 69, Short.MAX_VALUE))
                                    .addGroup(layout.createSequentialGroup()
                                        .addGap(18, 18, 18)
                                        .addComponent(textFieldInfor2))))
                            .addGroup(layout.createSequentialGroup()
                                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                    .addGroup(layout.createSequentialGroup()
                                        .addComponent(labelCodProd)
                                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                                        .addComponent(textFieldCodProd, javax.swing.GroupLayout.PREFERRED_SIZE, 84, javax.swing.GroupLayout.PREFERRED_SIZE))
                                    .addComponent(labelInformacoes))
                                .addGap(0, 0, Short.MAX_VALUE))
                            .addGroup(layout.createSequentialGroup()
                                .addComponent(labelNumVenda)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                .addComponent(textFieldNumVenda, javax.swing.GroupLayout.PREFERRED_SIZE, 56, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                                .addComponent(labelTipoPag)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                .addComponent(comboBoxTipoPag, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addGap(23, 23, 23)))))
                .addContainerGap())
            .addGroup(layout.createSequentialGroup()
                .addGap(89, 89, 89)
                .addComponent(jButton2, javax.swing.GroupLayout.PREFERRED_SIZE, 113, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(42, 42, 42)
                .addComponent(jButton3)
                .addGap(0, 0, Short.MAX_VALUE))
        );

        layout.linkSize(javax.swing.SwingConstants.HORIZONTAL, new java.awt.Component[] {labelNumVenda, labelTipoPag});

        layout.linkSize(javax.swing.SwingConstants.HORIZONTAL, new java.awt.Component[] {comboBoxTipoPag, textFieldNumVenda});

        layout.linkSize(javax.swing.SwingConstants.HORIZONTAL, new java.awt.Component[] {labelInfor1, labelInfor2});

        layout.linkSize(javax.swing.SwingConstants.HORIZONTAL, new java.awt.Component[] {jButton2, jButton3});

        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(labelIcone)
                    .addComponent(jLabel11))
                .addGap(11, 11, 11)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(labelNumVenda, javax.swing.GroupLayout.PREFERRED_SIZE, 29, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(textFieldNumVenda, javax.swing.GroupLayout.PREFERRED_SIZE, 29, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(labelTipoPag)
                    .addComponent(comboBoxTipoPag, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(labelCliente)
                    .addComponent(comboBoxCliente, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addGap(18, 18, 18)
                .addComponent(labelInformacoes, javax.swing.GroupLayout.PREFERRED_SIZE, 25, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(labelInfor1, javax.swing.GroupLayout.PREFERRED_SIZE, 26, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(textFieldInfor1, javax.swing.GroupLayout.PREFERRED_SIZE, 29, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(labelInfor2)
                    .addComponent(textFieldInfor2, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(layout.createSequentialGroup()
                        .addGap(53, 53, 53)
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(labelCodProd)
                            .addComponent(textFieldCodProd, javax.swing.GroupLayout.PREFERRED_SIZE, 27, javax.swing.GroupLayout.PREFERRED_SIZE))
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(labelQuantProd)
                            .addComponent(textFieldQuantProd, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)))
                    .addGroup(layout.createSequentialGroup()
                        .addGap(65, 65, 65)
                        .addComponent(btnAdcionarItem)))
                .addGap(18, 18, 18)
                .addComponent(jScrollPane2, javax.swing.GroupLayout.PREFERRED_SIZE, 91, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(18, 18, 18)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel10)
                    .addComponent(jTextField6, javax.swing.GroupLayout.PREFERRED_SIZE, 32, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, 35, Short.MAX_VALUE)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jButton2, javax.swing.GroupLayout.PREFERRED_SIZE, 36, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jButton3))
                .addGap(23, 23, 23))
        );

        layout.linkSize(javax.swing.SwingConstants.VERTICAL, new java.awt.Component[] {comboBoxCliente, labelCliente, labelNumVenda, labelTipoPag});

        layout.linkSize(javax.swing.SwingConstants.VERTICAL, new java.awt.Component[] {comboBoxTipoPag, textFieldNumVenda});

        layout.linkSize(javax.swing.SwingConstants.VERTICAL, new java.awt.Component[] {labelInfor1, labelInfor2});

        layout.linkSize(javax.swing.SwingConstants.VERTICAL, new java.awt.Component[] {textFieldInfor1, textFieldInfor2});

        layout.linkSize(javax.swing.SwingConstants.VERTICAL, new java.awt.Component[] {textFieldCodProd, textFieldQuantProd});

        layout.linkSize(javax.swing.SwingConstants.VERTICAL, new java.awt.Component[] {jButton2, jButton3});

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void textFieldNumVendaActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_textFieldNumVendaActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_textFieldNumVendaActionPerformed

    private void comboBoxClienteActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_comboBoxClienteActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_comboBoxClienteActionPerformed

    private void textFieldQuantProdActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_textFieldQuantProdActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_textFieldQuantProdActionPerformed

    private void jButton3ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButton3ActionPerformed

        this.dispose();
    }//GEN-LAST:event_jButton3ActionPerformed

    private void jButton2ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButton2ActionPerformed
        
        ControladorVendas control = new ControladorVendas();
        
        if(produtos == null || listaClientes == null){
            JOptionPane.showMessageDialog(null, "O sistema não possui clientes ou produtos cadastrados\n"
                                              + "Não é possível registrar a venda!");
            this.dispose();
            return;
        }
        
        novaVenda.setNumero(textFieldNumVenda.getText());
        novaVenda.setCliente( listaClientes[ comboBoxCliente.getSelectedIndex() ] );
        
        String nome = textFieldInfor1.getText();
        String numero = textFieldInfor2.getText();
        if((nome.isEmpty() || numero.isEmpty()) && comboBoxTipoPag.getSelectedIndex() != 0){
            JOptionPane.showMessageDialog(null, "Algum Dos Campos Está Vazio !!");
            return;
        }
        
        if(novaVenda.getContItens() == 0){
            JOptionPane.showMessageDialog(null, "A venda não possui Itens !!");
            return;
        }
        
        switch(comboBoxTipoPag.getSelectedIndex()){
            case 0:
                novaVenda.setTipoPgto(new Dinheiro("Dinheiro"));
                break;
            case 1:{
                novaVenda.setTipoPgto(new Cartao(nome, numero, "Cartão"));
                break;
            }
            case 2:{
                novaVenda.setTipoPgto(new Cheque(nome,numero, "Cheque"));
                break;
            }
        }
        
        novaVenda.setData(Calendar.getInstance());
        
        try {
            control.cadastrarVenda(novaVenda);
        } catch (IOException | ClassNotFoundException ex) {
            Logger.getLogger(CadastroDeVendas.class.getName()).log(Level.SEVERE, null, ex);
        }
        this.dispose();
    }//GEN-LAST:event_jButton2ActionPerformed

    private void comboBoxTipoPagFocusLost(java.awt.event.FocusEvent evt) {//GEN-FIRST:event_comboBoxTipoPagFocusLost
        switch(comboBoxTipoPag.getSelectedIndex()){
            case 0://Dinheiro
                labelInformacoes.setText("Informações");
                labelInfor1.setText("Nome");
                labelInfor2.setText("Numero");
                textFieldInfor1.setEnabled(false);
                textFieldInfor2.setEnabled(false);
                break;
            case 1://Cartão
                labelInformacoes.setText("Informações do Cartão");
                labelInfor1.setText("Nome do Titular");
                labelInfor2.setText("Numero do Cartão");
                textFieldInfor1.setEnabled(true);
                textFieldInfor2.setEnabled(true);
                break;
            case 2://cheque
                labelInformacoes.setText("Informações do cheque");
                labelInfor1.setText("Nome do emissor");
                labelInfor2.setText("Numero do cheque");
                textFieldInfor1.setEnabled(true);
                textFieldInfor2.setEnabled(true);
                break;
        }
    }//GEN-LAST:event_comboBoxTipoPagFocusLost

    private void formWindowOpened(java.awt.event.WindowEvent evt) {//GEN-FIRST:event_formWindowOpened
        DefaultComboBoxModel dCBM = new DefaultComboBoxModel();
        ControladorClientes control = new ControladorClientes();
        ControladorVendas controlVendas = new ControladorVendas();
        
        comboBoxCliente.setModel(dCBM);
        
        try {
            listaClientes = control.lerClientes();
            if(listaClientes != null){
                for(int i=0;i<listaClientes.length;i++){
                dCBM.addElement(listaClientes[i].getNome());
            }
        }else dCBM.addElement("Não ha clientes cadastrados");
            
        } catch (IOException | ClassNotFoundException ex) {
            Logger.getLogger(CadastroDeVendas.class.getName()).log(Level.SEVERE, null, ex);
        }
        
        try {
            textFieldNumVenda.setText(String.valueOf(controlVendas.getNumVendas()));
        } catch (IOException ex) {
            Logger.getLogger(CadastroDeVendas.class.getName()).log(Level.SEVERE, null, ex);
        }
        
        
    }//GEN-LAST:event_formWindowOpened

    private void btnAdcionarItemActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnAdcionarItemActionPerformed
        String codigo;
        int quantidade;
        String[] Linha = {"","","",""}; 
        
        codigo = textFieldCodProd.getText();
        quantidade = Integer.valueOf( textFieldQuantProd.getText());
        
        for(int i = 0;i<produtos.length;i++){
            if(codigo.equals(produtos[i].getCodigo())){
                Linha[0] = produtos[i].getCodigo();
                Linha[1] = produtos[i].getDescricao();
                Linha[2] = String.valueOf(quantidade);
                Linha[3] = String.valueOf(produtos[i].calcularPreco());
                dTM.addRow(Linha);
               
                novaVenda.addItem(produtos[i],quantidade);
                
                valorTotal += produtos[i].calcularPreco()*quantidade;
                
                jTextField6.setText(String.valueOf(valorTotal));
                return;
            }
        }
        JOptionPane.showMessageDialog(null,"Produto não encontrado");
    }//GEN-LAST:event_btnAdcionarItemActionPerformed

    /**
     * @param args the command line arguments
     */
    public static void main(String args[]) {
        /* Set the Nimbus look and feel */
        //<editor-fold defaultstate="collapsed" desc=" Look and feel setting code (optional) ">
        /* If Nimbus (introduced in Java SE 6) is not available, stay with the default look and feel.
         * For details see http://download.oracle.com/javase/tutorial/uiswing/lookandfeel/plaf.html 
         */
        try {
            for (javax.swing.UIManager.LookAndFeelInfo info : javax.swing.UIManager.getInstalledLookAndFeels()) {
                if ("Nimbus".equals(info.getName())) {
                    javax.swing.UIManager.setLookAndFeel(info.getClassName());
                    break;
                }
            }
        } catch (ClassNotFoundException ex) {
            java.util.logging.Logger.getLogger(CadastroDeVendas.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(CadastroDeVendas.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(CadastroDeVendas.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(CadastroDeVendas.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>

        /* Create and display the dialog */
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                CadastroDeVendas dialog;
                try {
                    dialog = new CadastroDeVendas(new javax.swing.JFrame(), true);
                    dialog.addWindowListener(new java.awt.event.WindowAdapter() {
                    @Override
                    public void windowClosing(java.awt.event.WindowEvent e) {
                        System.exit(0);
                    }
                });
                dialog.setVisible(true);
                } catch (IOException | ClassNotFoundException ex) {
                    Logger.getLogger(CadastroDeVendas.class.getName()).log(Level.SEVERE, null, ex);
                }
                
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton btnAdcionarItem;
    private javax.swing.JComboBox comboBoxCliente;
    private javax.swing.JComboBox comboBoxTipoPag;
    private javax.swing.JButton jButton2;
    private javax.swing.JButton jButton3;
    private javax.swing.JLabel jLabel10;
    private javax.swing.JLabel jLabel11;
    private javax.swing.JScrollPane jScrollPane1;
    private javax.swing.JScrollPane jScrollPane2;
    private javax.swing.JTable jTable1;
    private javax.swing.JTextField jTextField6;
    private javax.swing.JLabel labelCliente;
    private javax.swing.JLabel labelCodProd;
    private javax.swing.JLabel labelIcone;
    private javax.swing.JLabel labelInfor1;
    private javax.swing.JLabel labelInfor2;
    private javax.swing.JLabel labelInformacoes;
    private javax.swing.JLabel labelNumVenda;
    private javax.swing.JLabel labelQuantProd;
    private javax.swing.JLabel labelTipoPag;
    private javax.swing.JTable tabelaProdutos;
    private javax.swing.JTextField textFieldCodProd;
    private javax.swing.JTextField textFieldInfor1;
    private javax.swing.JTextField textFieldInfor2;
    private javax.swing.JTextField textFieldNumVenda;
    private javax.swing.JTextField textFieldQuantProd;
    // End of variables declaration//GEN-END:variables
}
