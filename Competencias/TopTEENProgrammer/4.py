def is_rotation(str1, str2):                                                    
  if len(str1) != len(str2):                                                    
    return False                                                                
                                                                                
  for index in xrange(len(str1)):                                                                                           
    if str2.startswith(str1[index:]) and str2.endswith(str1[:index]):           
      return True                                                               
                                                                                
  return False

word = raw_input()
word2 = raw_input()

if is_rotation(word,word2):
    print("Rotacion")
else:
    print("No rotacion")