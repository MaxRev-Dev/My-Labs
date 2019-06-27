

class Editor:
    def view_document(self):
        print("This is a document")
        pass
    def edit_document(self):
        print("You're using trial version. Editing only available in EditorPro")
        pass
    pass

class ProEditor(Editor):
    def view_document(self): 
        super().view_document()
        pass
    def edit_document(self):        
        print("Yay, thank you for purshasing license!")
        print("Now you can edit this document")
        print("[some imaginary editing tools))]")
        pass
    pass


key = "proEdit"
inkey = ""
editor = Editor()

while 1:    
    
    editor.view_document()
    editor.edit_document()
    if (inkey != key): 
        inkey = input("Please, enter license key: ")
        if (inkey == key):
           editor = ProEditor()
        else:
            print("Invalid license key. Falling back to simple editor(")
        pass 
    else:
        break
    pass 
pass

