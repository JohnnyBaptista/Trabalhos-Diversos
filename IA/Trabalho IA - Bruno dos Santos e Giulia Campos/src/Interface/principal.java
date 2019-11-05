package Interface;

import Classes.Coordenada;
import Classes.Tabuleiro;
import java.awt.Color;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.util.Date;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.JLabel;
import javax.swing.JOptionPane;

public class principal extends javax.swing.JFrame {

    private Tabuleiro tabuleiro = new Tabuleiro(3, this);

    private JLabel tabuleiro_lb[][] = new JLabel[tabuleiro.getDim()][tabuleiro.getDim()];
 
    public Date data = new Date();
    public String dataString = data.toString().replace(":", "-");
    public String fileName = "Relatorio_Execucao"+dataString.trim()+".txt"; 
    String userHomeFolder = System.getProperty("user.home");
    public File arquivo = new File(userHomeFolder,fileName);
    public FileOutputStream arqaux = new FileOutputStream(arquivo);
    
    private static long startValue;  
    private static long stopValue;  
    private static long timeDiff;  
         
    public principal() throws IOException {
        initComponents();
        iniciaTabuleiro();
    }

    public void iniciaTabuleiro() {
        tabuleiro_lb[0][0] = lblPos11;
        tabuleiro_lb[0][1] = lblPos12;
        tabuleiro_lb[0][2] = lblPos13;
        tabuleiro_lb[1][0] = lblPos21;
        tabuleiro_lb[1][1] = lblPos22;
        tabuleiro_lb[1][2] = lblPos23;
        tabuleiro_lb[2][0] = lblPos31;
        tabuleiro_lb[2][1] = lblPos32;
        tabuleiro_lb[2][2] = lblPos33;

    }
    
    public static void start() { //Inicia a contagem do tempo  
        startValue = System.currentTimeMillis();  
        stopValue = 0;  
        timeDiff = 0;  
       }  
  

    public static void stop() {  //Calcula o tempo demorado
        stopValue = System.currentTimeMillis();  
        timeDiff = stopValue - startValue;  
    }


    public void moverEspaco(Coordenada antiga, Coordenada nova) { //Move as peças pela interface

        String text_nova = tabuleiro_lb[nova.getLinha()][nova.getColuna()].getText();

        tabuleiro_lb[antiga.getLinha()][antiga.getColuna()].setText(text_nova);
        tabuleiro_lb[antiga.getLinha()][antiga.getColuna()].setSize(tabuleiro_lb[antiga.getLinha()][antiga.getColuna()].getSize());
        tabuleiro_lb[nova.getLinha()][nova.getColuna()].setText("");

        Color background_nova = tabuleiro_lb[nova.getLinha()][nova.getColuna()].getBackground();
        Color background_antiga = tabuleiro_lb[antiga.getLinha()][antiga.getColuna()].getBackground();
        tabuleiro_lb[nova.getLinha()][nova.getColuna()].setBackground(background_antiga);
        tabuleiro_lb[antiga.getLinha()][antiga.getColuna()].setBackground(background_nova);

    }
    
    public void bloqueiaBotoes(){
        btnOkEmbaralhar.setEnabled(false);
        btnSelecionar.setEnabled(false);
    }
    
    public void liberaBotoes(){
        btnOkEmbaralhar.setEnabled(true);
        btnSelecionar.setEnabled(true);
    }
    
    public void exibeQtdMovimentos(int qde){
            lblQtdMovimentos.setText("Quantidade de tentativas: " + qde);
    }
    
    public void exibeQtdMovimentosFeitos(int qde){
            lblQtdMovimentosFeitos.setText("Quantidade de movimentos feitos: " + qde);
    }
    
    public void exibeTempo(long qde){
            lblTempo.setText("Tempo (ms): " + qde);
    }
    
    public void limpaQtdMovimentos(){
        lblQtdMovimentos.setText("");
        lblQtdMovimentosFeitos.setText("");
        lblTempo.setText("");
    }
  
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {
        java.awt.GridBagConstraints gridBagConstraints;

        grpBuscas = new javax.swing.ButtonGroup();
        pnMenu = new javax.swing.JPanel();
        lblEmbaralhar = new javax.swing.JLabel();
        spnNEmbaralhar = new javax.swing.JSpinner();
        btnOkEmbaralhar = new javax.swing.JButton();
        lblPos13 = new javax.swing.JLabel();
        lblPos12 = new javax.swing.JLabel();
        lblPos23 = new javax.swing.JLabel();
        lblPos21 = new javax.swing.JLabel();
        lblPos22 = new javax.swing.JLabel();
        lblPos33 = new javax.swing.JLabel();
        lblPos31 = new javax.swing.JLabel();
        lblPos32 = new javax.swing.JLabel();
        lblPos11 = new javax.swing.JLabel();
        pnBuscas = new javax.swing.JPanel();
        lblBuscas = new javax.swing.JLabel();
        rbAleatoria = new javax.swing.JRadioButton();
        rbHeuristica1 = new javax.swing.JRadioButton();
        rbHeuristica2 = new javax.swing.JRadioButton();
        rbHeuristicaPessoal = new javax.swing.JRadioButton();
        btnSelecionar = new javax.swing.JButton();
        lblQtdMovimentos = new javax.swing.JLabel();
        lblQtdMovimentosFeitos = new javax.swing.JLabel();
        lblTempo = new javax.swing.JLabel();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        setTitle("Trabalho de IA");
        setMinimumSize(new java.awt.Dimension(356, 303));

        pnMenu.setBorder(javax.swing.BorderFactory.createEtchedBorder());
        pnMenu.setMaximumSize(new java.awt.Dimension(135, 71));
        pnMenu.setMinimumSize(new java.awt.Dimension(135, 71));

        lblEmbaralhar.setText("Embaralhar:");

        spnNEmbaralhar.setModel(new javax.swing.SpinnerNumberModel(1, 1, null, 1));
        spnNEmbaralhar.setMaximumSize(new java.awt.Dimension(29, 20));

        btnOkEmbaralhar.setText("OK");
        btnOkEmbaralhar.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnOkEmbaralharActionPerformed(evt);
            }
        });

        javax.swing.GroupLayout pnMenuLayout = new javax.swing.GroupLayout(pnMenu);
        pnMenu.setLayout(pnMenuLayout);
        pnMenuLayout.setHorizontalGroup(
            pnMenuLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
            .addGroup(pnMenuLayout.createSequentialGroup()
                .addGap(20, 20, 20)
                .addGroup(pnMenuLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(lblEmbaralhar)
                    .addGroup(pnMenuLayout.createSequentialGroup()
                        .addComponent(spnNEmbaralhar, javax.swing.GroupLayout.PREFERRED_SIZE, 79, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(btnOkEmbaralhar)))
                .addGap(14, 14, 14))
        );
        pnMenuLayout.setVerticalGroup(
            pnMenuLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(pnMenuLayout.createSequentialGroup()
                .addGap(8, 8, 8)
                .addComponent(lblEmbaralhar)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(pnMenuLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(spnNEmbaralhar, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(btnOkEmbaralhar))
                .addContainerGap(16, Short.MAX_VALUE))
        );

        lblPos13.setBackground(new java.awt.Color(0, 51, 255));
        lblPos13.setFont(new java.awt.Font("Stencil Std", 0, 24)); // NOI18N
        lblPos13.setForeground(new java.awt.Color(255, 255, 255));
        lblPos13.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        lblPos13.setText("3");
        lblPos13.setBorder(javax.swing.BorderFactory.createBevelBorder(javax.swing.border.BevelBorder.RAISED));
        lblPos13.setMaximumSize(new java.awt.Dimension(53, 53));
        lblPos13.setMinimumSize(new java.awt.Dimension(53, 53));
        lblPos13.setOpaque(true);
        lblPos13.setPreferredSize(new java.awt.Dimension(53, 53));

        lblPos12.setBackground(new java.awt.Color(0, 51, 255));
        lblPos12.setFont(new java.awt.Font("Stencil Std", 0, 24)); // NOI18N
        lblPos12.setForeground(new java.awt.Color(255, 255, 255));
        lblPos12.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        lblPos12.setText("2");
        lblPos12.setBorder(javax.swing.BorderFactory.createBevelBorder(javax.swing.border.BevelBorder.RAISED));
        lblPos12.setMaximumSize(new java.awt.Dimension(53, 53));
        lblPos12.setMinimumSize(new java.awt.Dimension(53, 53));
        lblPos12.setOpaque(true);
        lblPos12.setPreferredSize(new java.awt.Dimension(53, 53));

        lblPos23.setBackground(new java.awt.Color(0, 51, 255));
        lblPos23.setFont(new java.awt.Font("Stencil Std", 0, 24)); // NOI18N
        lblPos23.setForeground(new java.awt.Color(255, 255, 255));
        lblPos23.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        lblPos23.setText("6");
        lblPos23.setBorder(javax.swing.BorderFactory.createBevelBorder(javax.swing.border.BevelBorder.RAISED));
        lblPos23.setMaximumSize(new java.awt.Dimension(53, 53));
        lblPos23.setMinimumSize(new java.awt.Dimension(53, 53));
        lblPos23.setOpaque(true);
        lblPos23.setPreferredSize(new java.awt.Dimension(53, 53));

        lblPos21.setBackground(new java.awt.Color(0, 51, 255));
        lblPos21.setFont(new java.awt.Font("Stencil Std", 0, 24)); // NOI18N
        lblPos21.setForeground(new java.awt.Color(255, 255, 255));
        lblPos21.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        lblPos21.setText("4");
        lblPos21.setBorder(javax.swing.BorderFactory.createBevelBorder(javax.swing.border.BevelBorder.RAISED));
        lblPos21.setMaximumSize(new java.awt.Dimension(53, 53));
        lblPos21.setMinimumSize(new java.awt.Dimension(53, 53));
        lblPos21.setOpaque(true);
        lblPos21.setPreferredSize(new java.awt.Dimension(53, 53));

        lblPos22.setBackground(new java.awt.Color(0, 51, 255));
        lblPos22.setFont(new java.awt.Font("Stencil Std", 0, 24)); // NOI18N
        lblPos22.setForeground(new java.awt.Color(255, 255, 255));
        lblPos22.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        lblPos22.setText("5");
        lblPos22.setBorder(javax.swing.BorderFactory.createBevelBorder(javax.swing.border.BevelBorder.RAISED));
        lblPos22.setMaximumSize(new java.awt.Dimension(53, 53));
        lblPos22.setMinimumSize(new java.awt.Dimension(53, 53));
        lblPos22.setOpaque(true);
        lblPos22.setPreferredSize(new java.awt.Dimension(53, 53));

        lblPos33.setFont(new java.awt.Font("Stencil Std", 0, 24)); // NOI18N
        lblPos33.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        lblPos33.setMaximumSize(new java.awt.Dimension(53, 53));
        lblPos33.setMinimumSize(new java.awt.Dimension(53, 53));
        lblPos33.setOpaque(true);
        lblPos33.setPreferredSize(new java.awt.Dimension(53, 53));

        lblPos31.setBackground(new java.awt.Color(0, 51, 255));
        lblPos31.setFont(new java.awt.Font("Stencil Std", 0, 24)); // NOI18N
        lblPos31.setForeground(new java.awt.Color(255, 255, 255));
        lblPos31.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        lblPos31.setText("7");
        lblPos31.setBorder(javax.swing.BorderFactory.createBevelBorder(javax.swing.border.BevelBorder.RAISED));
        lblPos31.setMaximumSize(new java.awt.Dimension(53, 53));
        lblPos31.setMinimumSize(new java.awt.Dimension(53, 53));
        lblPos31.setOpaque(true);
        lblPos31.setPreferredSize(new java.awt.Dimension(53, 53));

        lblPos32.setBackground(new java.awt.Color(0, 51, 255));
        lblPos32.setFont(new java.awt.Font("Stencil Std", 0, 24)); // NOI18N
        lblPos32.setForeground(new java.awt.Color(255, 255, 255));
        lblPos32.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        lblPos32.setText("8");
        lblPos32.setBorder(javax.swing.BorderFactory.createBevelBorder(javax.swing.border.BevelBorder.RAISED));
        lblPos32.setMaximumSize(new java.awt.Dimension(53, 53));
        lblPos32.setMinimumSize(new java.awt.Dimension(53, 53));
        lblPos32.setOpaque(true);
        lblPos32.setPreferredSize(new java.awt.Dimension(53, 53));

        lblPos11.setBackground(new java.awt.Color(0, 51, 255));
        lblPos11.setFont(new java.awt.Font("Stencil Std", 0, 24)); // NOI18N
        lblPos11.setForeground(new java.awt.Color(255, 255, 255));
        lblPos11.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        lblPos11.setText("1");
        lblPos11.setBorder(javax.swing.BorderFactory.createBevelBorder(javax.swing.border.BevelBorder.RAISED));
        lblPos11.setMaximumSize(new java.awt.Dimension(53, 53));
        lblPos11.setMinimumSize(new java.awt.Dimension(53, 53));
        lblPos11.setOpaque(true);
        lblPos11.setPreferredSize(new java.awt.Dimension(53, 53));

        pnBuscas.setBorder(javax.swing.BorderFactory.createLineBorder(new java.awt.Color(153, 153, 153)));
        pnBuscas.setMaximumSize(new java.awt.Dimension(129, 162));
        pnBuscas.setMinimumSize(new java.awt.Dimension(129, 162));
        pnBuscas.setLayout(new java.awt.GridBagLayout());

        lblBuscas.setText("Buscas:");
        gridBagConstraints = new java.awt.GridBagConstraints();
        gridBagConstraints.gridx = 0;
        gridBagConstraints.gridy = 0;
        gridBagConstraints.anchor = java.awt.GridBagConstraints.NORTHWEST;
        gridBagConstraints.insets = new java.awt.Insets(12, 11, 0, 0);
        pnBuscas.add(lblBuscas, gridBagConstraints);

        grpBuscas.add(rbAleatoria);
        rbAleatoria.setSelected(true);
        rbAleatoria.setText("Aleatória");
        gridBagConstraints = new java.awt.GridBagConstraints();
        gridBagConstraints.gridx = 0;
        gridBagConstraints.gridy = 1;
        gridBagConstraints.gridwidth = 2;
        gridBagConstraints.anchor = java.awt.GridBagConstraints.NORTHWEST;
        gridBagConstraints.insets = new java.awt.Insets(7, 11, 0, 0);
        pnBuscas.add(rbAleatoria, gridBagConstraints);

        grpBuscas.add(rbHeuristica1);
        rbHeuristica1.setText("Heurística 1");
        gridBagConstraints = new java.awt.GridBagConstraints();
        gridBagConstraints.gridx = 0;
        gridBagConstraints.gridy = 2;
        gridBagConstraints.gridwidth = 3;
        gridBagConstraints.anchor = java.awt.GridBagConstraints.NORTHWEST;
        gridBagConstraints.insets = new java.awt.Insets(0, 11, 0, 0);
        pnBuscas.add(rbHeuristica1, gridBagConstraints);

        grpBuscas.add(rbHeuristica2);
        rbHeuristica2.setText("Heurística 2");
        gridBagConstraints = new java.awt.GridBagConstraints();
        gridBagConstraints.gridx = 0;
        gridBagConstraints.gridy = 3;
        gridBagConstraints.gridwidth = 3;
        gridBagConstraints.anchor = java.awt.GridBagConstraints.NORTHWEST;
        gridBagConstraints.insets = new java.awt.Insets(0, 11, 0, 0);
        pnBuscas.add(rbHeuristica2, gridBagConstraints);

        grpBuscas.add(rbHeuristicaPessoal);
        rbHeuristicaPessoal.setText("Heurística Pessoal");
        gridBagConstraints = new java.awt.GridBagConstraints();
        gridBagConstraints.gridx = 0;
        gridBagConstraints.gridy = 4;
        gridBagConstraints.gridwidth = 4;
        gridBagConstraints.anchor = java.awt.GridBagConstraints.NORTHWEST;
        gridBagConstraints.insets = new java.awt.Insets(0, 11, 0, 0);
        pnBuscas.add(rbHeuristicaPessoal, gridBagConstraints);

        btnSelecionar.setText("Selecionar");
        btnSelecionar.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnSelecionarActionPerformed(evt);
            }
        });
        gridBagConstraints = new java.awt.GridBagConstraints();
        gridBagConstraints.gridx = 0;
        gridBagConstraints.gridy = 5;
        gridBagConstraints.gridwidth = 5;
        gridBagConstraints.anchor = java.awt.GridBagConstraints.NORTHWEST;
        gridBagConstraints.insets = new java.awt.Insets(2, 45, 12, 20);
        pnBuscas.add(btnSelecionar, gridBagConstraints);

        lblQtdMovimentos.setFont(new java.awt.Font("Tahoma", 0, 12)); // NOI18N
        lblQtdMovimentos.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        lblQtdMovimentos.setBorder(javax.swing.BorderFactory.createBevelBorder(javax.swing.border.BevelBorder.RAISED));

        lblQtdMovimentosFeitos.setFont(new java.awt.Font("Tahoma", 0, 12)); // NOI18N
        lblQtdMovimentosFeitos.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        lblQtdMovimentosFeitos.setBorder(javax.swing.BorderFactory.createBevelBorder(javax.swing.border.BevelBorder.RAISED));

        lblTempo.setFont(new java.awt.Font("Tahoma", 0, 12)); // NOI18N
        lblTempo.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        lblTempo.setBorder(javax.swing.BorderFactory.createBevelBorder(javax.swing.border.BevelBorder.RAISED));

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(layout.createSequentialGroup()
                        .addGap(22, 22, 22)
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addGroup(layout.createSequentialGroup()
                                .addGap(59, 59, 59)
                                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                    .addGroup(layout.createSequentialGroup()
                                        .addComponent(lblPos31, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                                        .addGap(6, 6, 6)
                                        .addComponent(lblPos32, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                                        .addGap(6, 6, 6)
                                        .addComponent(lblPos33, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                                    .addGroup(layout.createSequentialGroup()
                                        .addComponent(lblPos21, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                        .addComponent(lblPos22, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                                        .addGap(5, 5, 5)
                                        .addComponent(lblPos23, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))))
                            .addGroup(layout.createSequentialGroup()
                                .addGap(58, 58, 58)
                                .addComponent(lblPos11, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                .addComponent(lblPos12, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addGap(6, 6, 6)
                                .addComponent(lblPos13, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)))
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                        .addComponent(pnBuscas, javax.swing.GroupLayout.PREFERRED_SIZE, 173, javax.swing.GroupLayout.PREFERRED_SIZE))
                    .addGroup(layout.createSequentialGroup()
                        .addContainerGap()
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
                            .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                .addComponent(lblQtdMovimentosFeitos, javax.swing.GroupLayout.PREFERRED_SIZE, 307, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addComponent(lblQtdMovimentos, javax.swing.GroupLayout.PREFERRED_SIZE, 307, javax.swing.GroupLayout.PREFERRED_SIZE))
                            .addComponent(lblTempo, javax.swing.GroupLayout.PREFERRED_SIZE, 307, javax.swing.GroupLayout.PREFERRED_SIZE))
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, 18, Short.MAX_VALUE)
                        .addComponent(pnMenu, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)))
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap(16, Short.MAX_VALUE)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(layout.createSequentialGroup()
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                                .addComponent(lblPos12, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addComponent(lblPos11, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                            .addComponent(lblPos13, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                        .addGap(6, 6, 6)
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(lblPos21, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                            .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                                .addComponent(lblPos23, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addComponent(lblPos22, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)))
                        .addGap(6, 6, 6)
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(lblPos31, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                            .addComponent(lblPos32, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                            .addComponent(lblPos33, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)))
                    .addComponent(pnBuscas, javax.swing.GroupLayout.PREFERRED_SIZE, 173, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(layout.createSequentialGroup()
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(pnMenu, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                    .addGroup(layout.createSequentialGroup()
                        .addGap(11, 11, 11)
                        .addComponent(lblQtdMovimentos, javax.swing.GroupLayout.PREFERRED_SIZE, 17, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(lblQtdMovimentosFeitos, javax.swing.GroupLayout.PREFERRED_SIZE, 17, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(lblTempo, javax.swing.GroupLayout.PREFERRED_SIZE, 17, javax.swing.GroupLayout.PREFERRED_SIZE))))
        );

        pack();
        setLocationRelativeTo(null);
    }// </editor-fold>//GEN-END:initComponents

    private void btnSelecionarActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnSelecionarActionPerformed
        bloqueiaBotoes();
            if (rbAleatoria.isSelected()) {
                start();
                tabuleiro.buscaAleatoria();
                stop();
                exibeTempo(timeDiff);

            } else if (rbHeuristica1.isSelected()) { 
                start();
                tabuleiro.buscaHeuristica1();
                stop();
                exibeTempo(timeDiff);
            } else if (rbHeuristica2.isSelected()) {
                start();
                tabuleiro.buscaHeuristica2();
                stop();
                exibeTempo(timeDiff);
            } else if (rbHeuristicaPessoal.isSelected()) {
                start();
                tabuleiro.buscaHeuristicaPessoal();
                stop();
                exibeTempo(timeDiff);
            }
    }//GEN-LAST:event_btnSelecionarActionPerformed

    private void btnOkEmbaralharActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnOkEmbaralharActionPerformed
        int valor = (int) (spnNEmbaralhar.getValue());
        if (valor >= 0){
            String gr = "\n \n Quantidade de movimentos para embaralhar: "+valor+"\n";
                System.out.println(gr);
            bloqueiaBotoes();
            limpaQtdMovimentos();
            tabuleiro.embaralhar(valor);
        } else JOptionPane.showMessageDialog(null,"Informe uma quantidade válida.");

    }//GEN-LAST:event_btnOkEmbaralharActionPerformed


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
            java.util.logging.Logger.getLogger(principal.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(principal.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(principal.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(principal.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                try {
                    new principal().setVisible(true);
                } catch (IOException ex) {
                    Logger.getLogger(principal.class.getName()).log(Level.SEVERE, null, ex);
                }
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton btnOkEmbaralhar;
    private javax.swing.JButton btnSelecionar;
    private javax.swing.ButtonGroup grpBuscas;
    private javax.swing.JLabel lblBuscas;
    private javax.swing.JLabel lblEmbaralhar;
    private javax.swing.JLabel lblPos11;
    private javax.swing.JLabel lblPos12;
    private javax.swing.JLabel lblPos13;
    private javax.swing.JLabel lblPos21;
    private javax.swing.JLabel lblPos22;
    private javax.swing.JLabel lblPos23;
    private javax.swing.JLabel lblPos31;
    private javax.swing.JLabel lblPos32;
    private javax.swing.JLabel lblPos33;
    private javax.swing.JLabel lblQtdMovimentos;
    private javax.swing.JLabel lblQtdMovimentosFeitos;
    private javax.swing.JLabel lblTempo;
    private javax.swing.JPanel pnBuscas;
    private javax.swing.JPanel pnMenu;
    private javax.swing.JRadioButton rbAleatoria;
    private javax.swing.JRadioButton rbHeuristica1;
    private javax.swing.JRadioButton rbHeuristica2;
    private javax.swing.JRadioButton rbHeuristicaPessoal;
    private javax.swing.JSpinner spnNEmbaralhar;
    // End of variables declaration//GEN-END:variables
}
