#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node Node;
typedef struct choice choice;

struct choice{
    char desc[1000],ch1[100], ch2[100];
    int num,hp,knights;
};

struct Node{
    choice *ch;
    Node *left, *right;
};

Node *root = NULL;

choice *new(char x[], int y , int z, char a[], char b[], int c){
    choice *t = malloc(sizeof(choice));
    strcpy(t->desc, x);
    strcpy(t->ch1, a);
    strcpy(t->ch2, b);
    t->num = y;
    t->hp = z;
    t->knights = c;
    return t;
}

Node *treeInsert(Node *root, choice *t){
    if (!root){
        Node *newNode = malloc(sizeof(Node));
        newNode->ch = t;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    } else{
        if (t->num < root->ch->num){
            root->left = treeInsert(root->left, t);
        } else{
            root->right = treeInsert(root->right, t);
    	}
    }
    return root;
}

void insert(char x[], int y , int z, char a[], char b[], int c){
    
    choice *n = new(x,y,z,a,b,c);
    root = treeInsert(root, n);

}
void score(choice *t){
    if((t->hp == 0)){
    	printf ("\tScore: %d/5\n\n",t->knights);
    	if(t->knights == 5){
    		printf("\tYou were a Great leader. All of your knights have survived!\n");
    	}else if(t->knights >= 3){
    		printf("\tYou were a Good leader. Most of your knights have survived!\n");
    	}else if(t->knights > 0){
    		printf("\tYou were a Bad leader. Only some of your knights have survived!\n");
    	} else {
    		printf("\tYou were a Terrible leader. All of your knights have died!\n");
    	}
    	exit(0);
    } else{
    	return;
    }
}
void printSt(choice* st){
    if(st->hp == 0){
    	printf("\n%s\n\n", st->desc);
    	score(st);
    	
    } else{
    	    printf("\nHP: %d\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tKnights:%d\n\n", st->hp, st->knights);
	    printf("%s\n\n", st->desc);
	    printf("\t1.%s\n", st->ch1);
	    printf("\t2.%s\n", st->ch2);
    }
}



void main(){
	
    int cho,hp;
    char a[1000],b[100],c[100];
    /*Root Node*/
    printf("\t\t\t\t\t\t\tTHE FABLED KNIGHTS OF LORDRAN\n\n\nUnder the raging downpour, 6 of Lordran's best knights are trudging through the Blackwood forest's vegetation. Not paying heed to the silver nails raining on their eyelids, the arrow of their focus only cared about it's target, the infamous wizard, Zephyr.They had been tasked with killing Zephyr by their king. Many a sunset later, the heroes reached their destination, Warwick Keep. \n\n\n");
	strcpy(a,"After a long and arduos journey, the group stands before the entrance of the decreipt ruins of Warwick keep. The knights await your orders, their trusted captain. What will be your orders?");
	strcpy(b,"Scout the area for a possible ambush.");
	strcpy(c,"Force the doors of the keep, open.");
	insert(a,100,100,b,c,5);
	
	/*Left Sub tree*/

	strcpy(a,"The knights separate into pairs to scout the area. You and another knight, Jaeger study the keep from a distance. You notice some sort of trap that would have activated if the doors were to be opened.You take initiative and de-activate the trap. Suddenly, you hear a sound from the front doors. What will you do?");
	strcpy(b,"Ask Jaeger to check it out.");
	strcpy(c,"Do nothing and wait for your comrades to arrive.");
	insert(a,50,100,b,c,5);
	
	strcpy(a,"Jaeger follows your command and proceeds to force the door open. Before the door could be opened by Jaeger, it is busted open by two skeletons. Before Jaeger could react, one of the skeleton smashes it's mace on his head. Dazed, Jaeger stumbles back only to be stabbed by the other skeleton. Jaeger crumples onto the ground. Enraged, you rush towards the skeletons. What attack will you use?");
	strcpy(b,"Use magic.");
	strcpy(c,"Use your sword.");
	insert(a,25,100,b,c,4);
	
	strcpy(a,"Your patience is rewarded as the doors are busted open by two skeletons. You and Jaeger swiftly dispatch the two skeletons. Hearing the commotion,The other knights quickly converge to your location. The now reformed group ,await your command once again. What will be your command?");
	strcpy(b,"Ask the mages to use an illumination spell and illuminate the keep before entering it.");
	strcpy(c,"Use a small illumination spell and lead the knights into the keep.");
	insert(a,75,100,b,c,5);
	
	strcpy(a,"You rush towards the skeletons trying to use magic. You are blindsided by a mace hit to your head.\n\n\t\t CRITICAL HIT -70 HP!\n\n All you can see is red. The last thing you hear is your comrades rushing to save you before being killed by the skeletons.\n\n\t\t -30 HP!\n\n Enraged by your death, the knights charge forward like a bull. But alas, without your leadership, they fail to kill Zephyr and are killed.\n\n\t\tYOU HAVE DIED!\n\n\t\tReason: You were ambushed by skeletons!\n\n");
	strcpy(b,"");
	strcpy(c,"");
	insert(a,12,0,b,c,0);
	
	strcpy(a,"While rushing the skeletons, you opt to use your sword, you quickly dispatch the skeletons off. The rest of the group converges to your location. They stare  at Jaeger's still form, horrified. You were all shook by his sudden death. The group failed to notice Zephyr staring at them from the crown. He casts and enormous spell. Noticing the mana concentration, you and the mages look at towards the crown, only to see Zephyr cast the spell towards you. What eill you do?");
	strcpy(b,"Order the mages to cast a protection spell. ");
	strcpy(c,"Order the knights to run into the keep.");
	insert(a,37,100,b,c,4);
	
	strcpy(a,"The mages try their best to protect the entire group. Unfortunately, they could not get to the warriors in time. \n\n\t\tBOOOOOOOOOM!!!!!!!!!!!!!!!!!!!\n\n The soldiers were obliterated in an instant. Enraged, you and your mages combine to cast a spell. With a warcry, you and the mages unleash the singlemost devastating spell ever casted. The spell obliterates the foundation of the keep, instantly causing the keep to fall. As the dust settles, you and the remaining mages mourn the death of your comrades.\n\n\t\tVICTORY ACHIEVED!\n\n\t\tReason: You have slain Zephyr!\n\n");
	strcpy(b,"");
	strcpy(c,"");
	insert(a,34,0,b,c,2);

	strcpy(a,"You and the warriors safely reach the keep. You turn back to see a gigantic  crater. The mages had been killed. Enraged, you quickly ascend the stairs, followed by you warriors. You bust the crown doors open. Zephyr, clearly perplexed about how you survived, calls upon his army of undead minions using his remaining mana, the skeletons. The skeletons charge at you. What will you do?");
	strcpy(b,"Charge recklessly towards Zephyr.");
	strcpy(c,"Hold back the skeletons.");
	insert(a,40,100,b,c,2);
	
	strcpy(a,"Not caring about your wellbeing, you rush towards Zephyr.While charging towards Zephyr ,you get hit by a skeleton.\n\n\t\t- 20 H\n\n Before getting swarmed by the skeletons you use an explosive spell near you.\n\n\t\tBOOOM!! -50HP\n\nYour vision is blurry. You look back at your soldiers, only to see them getting mauled to death.Seeing their deaths snapped something inside you. Letting out a warcry you threw your sword at Zephyr. Before the sword could hit it's mark, you are met with a mace to the face, courtesy of the mace weilding skeleton. The last thing you hear is the gurgling of blood coming from the direction of Zephyr.\n\n\t\tHEROIC SACRIFICE ACHIEVED\n\n\t\tReason: You and your knights died while fulfilling your mission\n\n");
	strcpy(b,"");
	strcpy(c,"");
	insert(a,39,0,b,c,0);
	
	strcpy(a,"Trying to hold back the endless onslaught of skeletons, proved to be futile without the help of the mages. You are overrun by skeletons from both sides.\n\n\t\t-100 HP\n\n The last thing you hear are your comrade's screams echoing throughout the keep\n\n\t\t YOU HAVE DIED!\n\n\t\tReason: Your knights couldn't hold back the skeletons!\n\n");
	strcpy(b,"");
	strcpy(c,"");
	insert(a,41,0,b,c,0);
	
	strcpy(a,"The illumination seems to alert Zephyr as he looks down on the group from the crown of the keep. Before the mages could attack, Zephyr moves back into the crown. As the knights rush throught the stairs, a strange rattling seems to pierce the eerie silence. The rattling grows louder and louder as the group draws closer to the crown. The rattling  turns out to be a massive group of skeletons created by Zephyr. The knights look towards you for orders. Which formation of attack will you choose?");
	strcpy(b,"Mages as the rear guard and you and the warriors as the vanguard.");
	strcpy(c,"You and the mages as the rearguard and the warriors as the vanguard.");
	insert(a,62,100,b,c,5);
	
	strcpy(a,"The formation is a great success! The vanguard takes some minor hits from trying to stop the skeletons.\n\n\t\t -20HP\n\nThe mages work in tandem to thin out the crowd. Suddenly, you hear rattling from behind. Zephyr has sent some skeletons to ambush you from behind! What will you do?");
	strcpy(b,"Ask the vanguard to stand their ground and help the mages.");
	strcpy(c,"Ask the mages to take care of their predicament.");
	insert(a,56,80,b,c,5);
	
	strcpy(a,"The formation is a success! The vanguard takes some solid hits but with you and the mages combining your strength, the skeletons were thinned out greatly. Zephyr sends out more skeletons in desperation.Suddenly, you hear rattling from behind. Zephyr has sent some skeletons to ambush you from behind! What will you do?");
	strcpy(b,"Ask the mages to prepare a powerful spell while the warriors open the doors.");
	strcpy(c,"Ask the warriors to prepare to rush and distract Zephyr and the mages to blast the doors open.");
	insert(a,68,100,b,c,5);
	
	strcpy(a,"\t\t-20 HP\n\nYou take some hits as you leap into the fray and make short work of the ambushing skeletons, with the help of the mages. The vanguard has suffered some hits as it advances throught the onslaught of skeletons. Nevertheless, the group closes in on Zephyr. Zephyr seeing himself losing, in a last ditch effort uses his remaining mana and combines all the skeletons into a massive skeleton! The giant skeleton starts moving towards the group, ready to smash them into pieces. What should the knights do?");
	strcpy(b,"Try to defeat the Skeleton.");
	strcpy(c,"The rest of the knights distract the skeleton while you go after Zephyr.");
	insert(a,53,60,b,c,5);
	
	strcpy(a,"The mages shift their focus towards the ambushing skeletons. Unfortunately, without the mages help, the vanguard is quickly overrun by the skeleton army.\n\n\t\t-80 HP\n\n The last thing you hear are your comrade's screams echoing throughout the keep\n\n\t\t YOU HAVE DIED!\n\n\t\tReason: Your formation failed!\n\n");
	strcpy(b,"");
	strcpy(c,"");
	insert(a,59,0,b,c,0);
	
	strcpy(a,"Knowing that Zephyr must have used up all his mana to create this abomination, you command your mages to take out the skeleton's limbs while you and your warriors keep it distracted. The plan works as slowly the lumbering giant is brought down. Knowing that the skeleton's death spelled his impending demise, Zephyr starts pleading for his life. You move near Zephyr and look towards your knights. 'Victory is ours!' was the last thing Zephyr heard before you beheaded him in one single strike.\n\n\t\tHEROIC VICTORY ACHIEVED!\n\n\t\tReason: You have slain Zephyr!\n\n");
	strcpy(b,"");
	strcpy(c,"");
	insert(a,52,0,b,c,5);

	strcpy(a,"Narrowly avoiding the skeleton's hand, you bolt forward seeking to end Zephyr. Panicking, Zephyr commands the distracted skeleton to kill you. The skeleton ignores the knights and tries to punch you. 'MOVE!' ,the knights screamed as the two mages cast a spell towards Zephyr. Unable to move out of the way in time, you are crushed by the skeleton's gigantic hand while Zephyr is killed by the spell.\n\n\t\t-60 HP\n\n The Knights mourn your death, as they retrieve you sword from your remains.\n\n\t\t HEROIC DEATH ACHIEVED!\n\n\t\tReason: You sacrificed yourself to save your knights!");
	strcpy(b,"");
	strcpy(c,"");
	insert(a,54,0,b,c,5);
	
	strcpy(a,"With the small light illuminating the way, the knights ascend the keep, towards it's crown. Before reaching the crown doors, you give some orders to the knights. What will you say?");
	strcpy(b,"Ask the mages to prepare a powerful spell while the warriors open the doors.");
	strcpy(c,"Ask the warriors to prepare to rush and distract Zephyr and the mages to blast the doors open.");
	insert(a,87,100,b,c,5);
	
	strcpy(a,"With the doors open, the mages rush into the room. Zephyr is utterly surprised, for he understimated the knights. The mages cast the spell, killing Zephyr before he could even have a chance to defend himself. The knights cheer for they have slain this animal masquerading as a man.\n\n\t\tHEROIC VICTORY ACHIEVED!\n\n\t\tReason: Your intuitive plan caught Zephyr off guard leading to his demise.\n\n");
	strcpy(b,"");
	strcpy(c,"");
	insert(a,81,0,b,c,5);
	
	strcpy(a,"With the doors blasted open, the warriors rush into the room with a war cry. Zephyr is utterly surprised, for he understimated the knights. The surprise morphs into anger as he quickly begins to cast a spell aimed for the soldiers.Before he could cast the spell, you come rushing in with a spell that required your entire mana reserves and obliterate Zephyr. The knights cheer for they have slain this animal masquerading as a man.\n\n\t\tHEROIC VICTORY ACHIEVED!\n\n\t\tReason: Your intuitive plan caught Zephyr off guard leading to his demise.\n\n");
	strcpy(b,"");
	strcpy(c,"");
	insert(a,93,0,b,c,5);

	strcpy(a,"You try to single handedly take out the ambushing skeletons. Eventhough you were casting your best spells, you could not take out the ambush. You are overrun by skeletons from both sides.\n\n\t\t-100 HP\n\nThe last thing you hear are your comrade's screams echoing throughout the keep\n\n\t\t YOU HAVE DIED!\n\n\t\tReason: Your formation failed!\n\n");
	strcpy(b,"");
	strcpy(c,"");
	insert(a,65,0,b,c,0);
	
	strcpy(a,"\t\t-20 HP\n\n With a few close calls, you and the other mage succeed in distrupting the ambush. Both of you turn back to see ur formation about to be overrun. You see the other mage looking back at you. What will you do?");
	strcpy(b,"Combine with the mages and take out Zephyr.");
	strcpy(c,"Try to help the vanguard.");
	insert(a,71,80,b,c,5);
	
	strcpy(a,"You and the mages combine to cast a powerful spell. Unfortunately, the warriors at the front are overrun by the skeletons as the casting is completed. With a warcry, you and the mages unleash the singlemost devastating spell ever casted. The spell obliterates the skeletons and zooms towards Zephyr. The last thing Zephyr sees is white. \n\n\t\tBOOOOOOOOOOOOOOOOOOOOOOOOOM!!!!!!!!!!!!!!!!!!!!!!\n\nThe spell shakes the very foundation of the keep as you and the mages rush out of the keep, carrying the fallen warriors.As the keep crumbles down, you are left pondering whether you could have saved your comrades or not.\n\n\t\tHEROIC VICTORY ACHIEVED!\n\n\t\tReason: Zephyr has been obliterated by your mages.");
	strcpy(b,"");
	strcpy(c,"");
	insert(a,70,0,b,c,2);
	
	strcpy(a,"You and your mages try to help the vanguard, but alas your efforts are in vain as you are overrun by the skelleton army.n\n\t\t-80 HP\n\n The last thing you hear are your comrade's screams echoing throughout the keep\n\n\t\t YOU HAVE DIED!\n\n\t\tReason: Your formation failed!\n\n");
	strcpy(b,"");
	strcpy(c,"");
	insert(a,72,0,b,c,0);
	
	
	/*Right Sub tree*/
        
	strcpy(a,"While the group tries to force the door open, a small tick echoes throught out the keep. The group now aware of what had transpired, tries to move away from the doors. But, alas their efforts were in vain.Your knights trying to save you is the last thing you see before an explosion engulfs you all.You are thrown back like a ragdoll and lose conciousness.\n\n\t\t -70 HP\n\n \t\t You feel like your floating in an endless void. Your body seems to be numb. Your eyelids feel heavy. 'I am so tired.Should I just rest?', you think. What will you do?");
	strcpy(b,"Give up your fight against sleep and rest.");
	strcpy(c,"Struggle to wake up.");
	insert(a,150,30,b,c,0);
	
	strcpy(a,"You slowly lose conciousness and rest..... forever\n\n\t\t -30 HP\n\n \t\tYOU HAVE DIED\n\n\t\t Reason: You gave up.");
	strcpy(b,"");
	strcpy(c,"");
	insert(a,125,0,b,c,0);
	
	strcpy(a,"You slowly open your eyes to the dizzy sky trying to remember what happened before you hit your head. You froze the very moment that you realised you lef your comrades to their graves. A plethora of emotions rattles the rage inside you. What will be your next action?");
	strcpy(b,"Heal yourself before taking the fight to Zephyr. ");
	strcpy(c,"Avenge your comrades now.");
	insert(a,175,30,b,c,0);
	
	strcpy(a,"You take the pragmatic approach and heal yourself with magic.\n\n\t\t+20 HP\n\nIt is not long before you ascend The stairs that lead to the crown of the keep. You crawl behind a wall to get a peek of the villain that started this all. You feel it is the right moment to attack after seeing the unguarded zephyr.Zephyr, underestimated the knights thinking they are all dead. You pounce like a tiger with the sword towards him but he catches you off guard with a magic dagger to  the neck.\n\n\t\t-50 HP\n\n THe last thing you see is your sword slicing his neck like a hot knife through butter.\n\n\t\tHEROIC SACRIFICE ACHIEVED!\n\n\t\tReason: You and Zephyr killed each other.\n\n");
	strcpy(b,"");
	strcpy(c,"");
	insert(a,162,0,b,c,0);
	
	strcpy(a,"There is no time for yourself, you must avenge those who were beside you. You slowly drag yourself up the stairs just to see the horrific sight of the the reanimated bodies of your fallen comrades. A Demonic laugh erupted from from zephyr, which makes you think about how vicious dark magic is. Zephyr bellows 'there is no turning back now, you need to to end them of their misery'. Clouded by tears, you turn your heart into stone and charge towards the shambling bodies of your comrades, with all your might. It is tragic to see your comrade pierce his blade through your heart.\n\n\t\t-30 HP\n\n\t\tYOU HAVE DIED!\n\n\t\tReason: Once a comrade, now a mindless husk, put an end to your life\n\n");
	strcpy(b,"");
	strcpy(c,"");
	insert(a,187,0,b,c,0);
	
	     
    Node *t = root;
        
    do{
    	printSt(t->ch);
        hp = t->ch->hp;
        printf("\n\tEnter your choice: ");
        scanf("%d",&cho);
        switch(cho){
        	case 1:
        		t = t->left;
        		break;
	
		case 2:
			t = t->right;
			break;
		
		default:
			printf("\nEnter 1 or 2!\n");
			break;
        }
    } while (1);

}

