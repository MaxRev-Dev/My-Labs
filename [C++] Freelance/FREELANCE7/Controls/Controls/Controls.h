яю 
 / /   C o n t r o l s . h   :   m a i n   h e a d e r   f i l e   f o r   t h e   P R O J E C T _ N A M E   a p p l i c a t i o n  
 / /  
  
 # p r a g m a   o n c e  
  
 # i f n d e f   _ _ A F X W I N _ H _ _  
 	 # e r r o r   " i n c l u d e   ' s t d a f x . h '   b e f o r e   i n c l u d i n g   t h i s   f i l e   f o r   P C H "  
 # e n d i f  
  
 # i n c l u d e   " r e s o u r c e . h " 	 	 / /   m a i n   s y m b o l s  
  
  
 / /   C C o n t r o l s A p p :  
 / /   S e e   C o n t r o l s . c p p   f o r   t h e   i m p l e m e n t a t i o n   o f   t h i s   c l a s s  
 / /  
  
 c l a s s   C C o n t r o l s A p p   :   p u b l i c   C W i n A p p  
 {  
 p u b l i c :  
 	 C C o n t r o l s A p p ( ) ;  
  
 / /   O v e r r i d e s  
 p u b l i c :  
 	 v i r t u a l   B O O L   I n i t I n s t a n c e ( ) ;  
  
 / /   I m p l e m e n t a t i o n  
  
 	 D E C L A R E _ M E S S A G E _ M A P ( )  
 } ;  
  
 e x t e r n   C C o n t r o l s A p p   t h e A p p ;  
 