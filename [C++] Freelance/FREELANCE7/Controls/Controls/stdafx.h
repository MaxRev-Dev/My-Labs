яю 
 / /   s t d a f x . h   :   i n c l u d e   f i l e   f o r   s t a n d a r d   s y s t e m   i n c l u d e   f i l e s ,  
 / /   o r   p r o j e c t   s p e c i f i c   i n c l u d e   f i l e s   t h a t   a r e   u s e d   f r e q u e n t l y ,  
 / /   b u t   a r e   c h a n g e d   i n f r e q u e n t l y  
  
 # p r a g m a   o n c e  
  
 # i f n d e f   V C _ E X T R A L E A N  
 # d e f i n e   V C _ E X T R A L E A N                         / /   E x c l u d e   r a r e l y - u s e d   s t u f f   f r o m   W i n d o w s   h e a d e r s  
 # e n d i f  
  
 # i n c l u d e   " t a r g e t v e r . h "  
  
 # d e f i n e   _ A T L _ C S T R I N G _ E X P L I C I T _ C O N S T R U C T O R S             / /   s o m e   C S t r i n g   c o n s t r u c t o r s   w i l l   b e   e x p l i c i t  
  
 / /   t u r n s   o f f   M F C ' s   h i d i n g   o f   s o m e   c o m m o n   a n d   o f t e n   s a f e l y   i g n o r e d   w a r n i n g   m e s s a g e s  
 # d e f i n e   _ A F X _ A L L _ W A R N I N G S  
  
 # i n c l u d e   < a f x w i n . h >                   / /   M F C   c o r e   a n d   s t a n d a r d   c o m p o n e n t s  
 # i n c l u d e   < a f x e x t . h >                   / /   M F C   e x t e n s i o n s  
  
  
 # i n c l u d e   < a f x d i s p . h >                 / /   M F C   A u t o m a t i o n   c l a s s e s  
  
  
  
 # i f n d e f   _ A F X _ N O _ O L E _ S U P P O R T  
 # i n c l u d e   < a f x d t c t l . h >                       / /   M F C   s u p p o r t   f o r   I n t e r n e t   E x p l o r e r   4   C o m m o n   C o n t r o l s  
 # e n d i f  
 # i f n d e f   _ A F X _ N O _ A F X C M N _ S U P P O R T  
 # i n c l u d e   < a f x c m n . h >                           / /   M F C   s u p p o r t   f o r   W i n d o w s   C o m m o n   C o n t r o l s  
 # e n d i f   / /   _ A F X _ N O _ A F X C M N _ S U P P O R T  
  
 # i n c l u d e   < a f x c o n t r o l b a r s . h >           / /   M F C   s u p p o r t   f o r   r i b b o n s   a n d   c o n t r o l   b a r s  
 # i n c l u d e   < a f x w i n . h >  
  
  
  
  
  
  
  
  
  
 # i f d e f   _ U N I C O D E  
 # i f   d e f i n e d   _ M _ I X 8 6  
 # p r a g m a   c o m m e n t ( l i n k e r , " / m a n i f e s t d e p e n d e n c y : \ " t y p e = ' w i n 3 2 '   n a m e = ' M i c r o s o f t . W i n d o w s . C o m m o n - C o n t r o l s '   v e r s i o n = ' 6 . 0 . 0 . 0 '   p r o c e s s o r A r c h i t e c t u r e = ' x 8 6 '   p u b l i c K e y T o k e n = ' 6 5 9 5 b 6 4 1 4 4 c c f 1 d f '   l a n g u a g e = ' * ' \ " " )  
 # e l i f   d e f i n e d   _ M _ X 6 4  
 # p r a g m a   c o m m e n t ( l i n k e r , " / m a n i f e s t d e p e n d e n c y : \ " t y p e = ' w i n 3 2 '   n a m e = ' M i c r o s o f t . W i n d o w s . C o m m o n - C o n t r o l s '   v e r s i o n = ' 6 . 0 . 0 . 0 '   p r o c e s s o r A r c h i t e c t u r e = ' a m d 6 4 '   p u b l i c K e y T o k e n = ' 6 5 9 5 b 6 4 1 4 4 c c f 1 d f '   l a n g u a g e = ' * ' \ " " )  
 # e l s e  
 # p r a g m a   c o m m e n t ( l i n k e r , " / m a n i f e s t d e p e n d e n c y : \ " t y p e = ' w i n 3 2 '   n a m e = ' M i c r o s o f t . W i n d o w s . C o m m o n - C o n t r o l s '   v e r s i o n = ' 6 . 0 . 0 . 0 '   p r o c e s s o r A r c h i t e c t u r e = ' * '   p u b l i c K e y T o k e n = ' 6 5 9 5 b 6 4 1 4 4 c c f 1 d f '   l a n g u a g e = ' * ' \ " " )  
 # e n d i f  
 # e n d i f  
  
  
 