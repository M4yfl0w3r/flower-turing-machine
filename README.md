## Turing Machine

Turing machine simulator written in C++

Single instruction: `S_0,q_i,S_z,q_j,L/R`
- `S_0` - symbol read
- `q_i` - current state
- `S_z` - symbol to write at the current field
- `q_j` - new state 
- `L/R` - move left / right 

Tape form: `#(symbols)#`
- available symbols: # 1 0 x L R
  - \# - an empty field
  - x - end state

Tape is being read as an program input <br/>
Instructions are being read from a file instructions.txt




