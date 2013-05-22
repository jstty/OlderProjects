/* //////////////////////////////////////////////////////////////////////
 Program Name:  cLvl_Ring01.cpp
 Programmer:    Joseph E. Sutton
 Start Date:    2006-07-03
 Updated:       
 Version:       1.00
 Description:   
   Level Class Source File
   
////////////////////////////////////////////////////////////////////// */

#include "main.h"

cLvl_Ring01::cLvl_Ring01()
{
}

cLvl_Ring01::~cLvl_Ring01()
{

}


//
int cLvl_Ring01::Init()
{
   uInt32 i;

   if(info != NULL)
   {
      if(info->display == NULL) return 2;
      m_display = info->display;

      m_layers = new cLayerMngr();
      m_screen_x = 0;
      m_screen_y = 0;
      m_screen_w = 714;
      m_screen_h = 501;
      m_screen_buff = create_bitmap(m_screen_w, m_screen_h);
      

      // Zones
      m_zones = new cZones();
      m_zones->Load("data/stadium/0/stadium.zones");


      // load/init script engine
      m_se = new cScriptEngine();
      m_se->Init();
      m_se->Load("data/level_scripts/ring.js");
      info->se = m_se; // set level info script engine
      
      // init all players
      m_sp1 = new cScriptPlayer();
      m_p1  = m_sp1->Init(m_se->GetContext(), m_se->GetGObject());

      m_sp2 = new cScriptPlayer();
      m_p2  = m_sp2->Init(m_se->GetContext(), m_se->GetGObject());

      // start engine
      m_se->Start();

      //
      m_ring_status_menu = new cRingStatusMenu();
      m_ring_status_menu->Init();
      
      //
      m_bkg = new cLayer();
      m_bkg->SetName("Bkg");
         //
         m_arena = new cImage("arena");
         m_arena->Load("data/stadium/0/arena.anim");
         m_arena->Anim()->Play();
         m_bkg->Add(m_arena);

         m_titan = new cTitantron();         
         m_bkg->Add(m_titan);

      //
      m_wmngr = new cWrestlerMngr();
      m_wmngr->Load("data/wrestler/wrestlers.list");

      // players
         m_pmngr = new cPlayerMngr();
         m_zones->SetPlayerMngr(m_pmngr);
         info->pmngr = m_pmngr;

         m_p1->SetWrestler( m_wmngr->Find("HH") );
         m_p1->SetXZ(135, 175);
         //m_p1->m_self->AnimSelect("walk_d_l");
         m_p1->AttachInput(info->p[PL_1]);

         m_p2->SetWrestler( m_wmngr->Find("HH") );
         m_p2->SetXZ(180, 175);
         //m_p2->m_self->AnimSelect("walk_d_r");
         m_p2->AttachInput(info->p[PL_2]);

         m_p1->AttachTarget(m_p2);
         m_p2->AttachTarget(m_p1);

         m_pmngr->AddPlayer(m_p1);
         m_pmngr->AddPlayer(m_p2);
        
         m_titan->GetFocusObject(m_p1);

         m_ring_status_menu->SetPlayer(0, m_p1, 0, 1);
         m_ring_status_menu->SetPlayer(1, m_p2, 1, 2);
         m_ring_status_menu->Load();
         //

      //
      for(i = 0; i < NUM_RING_LAYERS; ++i)
      {
         m_ring_layers[i] = new cLayer();
      }

      m_ring_layers[0]->SetName("Ring");
         m_ring = new cImage("ring");
         m_ring->LoadImage("data/stadium/0/ring.bmp");
         m_ring->SetXY(165, 157);
         m_ring_layers[0]->Add(m_ring);

         m_ring_layers[1]->SetName("Backropes");
         m_backropes = new cImage("backropes");
         m_backropes->LoadImage("data/stadium/backrope.bmp");
         m_backropes->SetXY(197, 97);
         m_ring_layers[1]->Add(m_backropes);

         //
         m_ring_layers[2]->SetName("Sideropes Left Bottom");
         m_sideropebottom_l = new cImage("sideropebottom_l");
         m_sideropebottom_l->Load("data/stadium/sideropebottom_l.anim");
         m_sideropebottom_l->SetXY(186, 149);
         m_ring_layers[2]->Add(m_sideropebottom_l);

         m_ring_layers[3]->SetName("Sideropes Right Bottom");
         m_sideropebottom_r = new cImage("sideropebottom_r");
         m_sideropebottom_r->Load("data/stadium/sideropebottom_r.anim");
         m_sideropebottom_r->SetXY(493, 149);
         m_ring_layers[3]->Add(m_sideropebottom_r);

         //
         m_ring_layers[4]->SetName("Sideropes Left Top");
         m_sideropetop_l = new cImage("sideropetop_l");
         m_sideropetop_l->Load("data/stadium/sideropetop_l.anim");
         m_sideropetop_l->SetXY(183, 132);
         m_ring_layers[4]->Add(m_sideropetop_l);


         m_ring_layers[5]->SetName("Sideropes Right Top");
         m_sideropetop_r = new cImage("sideropetop_r");
         m_sideropetop_r->Load("data/stadium/sideropetop_r.anim");
         m_sideropetop_r->SetXY(496, 132);
         m_ring_layers[5]->Add(m_sideropetop_r);

         //
         m_ring_layers[6]->SetName("Frontropes");
         m_frontropes = new cImage("frontropes");
         m_frontropes->LoadImage("data/stadium/frontrope.bmp");
         m_frontropes->SetXY(165, 277);
         m_ring_layers[6]->Add(m_frontropes);


      //
      m_ring_camera = new cRingCamera();
      m_ring_camera->SetFirst(m_p1);
      m_ring_camera->SetSecond(m_p2);
      m_ring_camera->SetRingSize(m_screen_w, m_screen_h);

      //
      m_fr_comm = new cLayer();
      m_fr_comm->SetName("FrontRow Comm");

         m_comm_delay = 0;
         //
         m_commintator = new cImage("commintator");
         m_commintator->Load("data/stadium/commintator.anim");
         m_commintator->SetXY(294, 428);
         m_commintator->Anim()->Play();
         m_fr_comm->Add(m_commintator);

         m_frontrow_l = new cImage("frontrow_l");
         m_frontrow_l->Load("data/stadium/frontrow_l.anim");
         m_frontrow_l->SetXY(75, 428);
         m_frontrow_l->Anim()->Play();
         m_fr_comm->Add(m_frontrow_l);

         m_frontrow_r = new cImage("frontrow_r");
         m_frontrow_r->Load("data/stadium/frontrow_r.anim");
         m_frontrow_r->SetXY(420, 428);
         m_frontrow_r->Anim()->Play();
         m_fr_comm->Add(m_frontrow_r);


      // 
      m_layers->Add(m_bkg);

      // ring
      m_layers->Add( m_zones->GetLayer(0) );  // outside_top
      m_layers->Add( m_zones->GetLayer(1) );  // outside_left
      m_layers->Add( m_zones->GetLayer(2) );  // outside_right
      m_layers->Add( m_ring_layers[0] );      // Ring
      m_layers->Add( m_zones->GetLayer(6) );  // apron_rear
      
      m_layers->Add( m_ring_layers[1] );      // back ropes

      m_layers->Add( m_zones->GetLayer(7) );  // apron_left1
      m_layers->Add( m_ring_layers[2] );      // Sideropes Left Bottom
      m_layers->Add( m_zones->GetLayer(8) );  // apron_right1
      m_layers->Add( m_ring_layers[3] );      // Sideropes Right Bottom

      m_layers->Add( m_zones->GetLayer(9) );  // apron_left2
      m_layers->Add( m_ring_layers[4] );      // Sideropes Left Top
      m_layers->Add( m_zones->GetLayer(10) ); // apron_right2
      m_layers->Add( m_ring_layers[5] );      // Sideropes Right Top

      //m_layers->Add( m_zones->GetLayer(13) ); // back turnbuckle left
      //m_layers->Add( m_zones->GetLayer(14) ); // back turnbuckle right

      m_layers->Add( m_zones->GetLayer(11) ); // ring
      m_layers->Add( m_ring_layers[6] );      // Frontropes

      //m_layers->Add( m_zones->GetLayer(15) ); // front turnbuckle left
      //m_layers->Add( m_zones->GetLayer(16) ); // front turnbuckle right

      m_layers->Add( m_zones->GetLayer(12) ); // apron_front
      m_layers->Add( m_zones->GetLayer(3) );  // outside_bottom
      m_layers->Add( m_zones->GetLayer(4) );  // left ring entrance
      m_layers->Add( m_zones->GetLayer(5) );  // right ring entrance

      m_layers->Add(m_fr_comm); // front crowd + commentators

      //
      m_sp1->PlayerInit();
      m_sp2->PlayerInit();

      return 0;
   }

   return 1;
}


//
int cLvl_Ring01::Exit()
{
   uInt32 i;

   m_ring_status_menu->Exit();
   DELETE(m_ring_status_menu);

   DELETE(m_ring);
   DELETE(m_arena);

   //
   DELETE(m_backropes);
   DELETE(m_frontropes);

   DELETE(m_sideropebottom_l);
   DELETE(m_sideropetop_r);

   //
   DELETE(m_bkg);

   for(i = 0; i < NUM_RING_LAYERS; ++i)
   {
      DELETE(m_ring_layers[i]);
   }

   //
   DELETE(m_fr_comm);
   DELETE(m_commintator);
   DELETE(m_frontrow_l);
   DELETE(m_frontrow_r);

   DELETE(m_zones);

   DELETE(m_wmngr);
   DELETE(m_pmngr);

   //
   if(m_screen_buff != NULL) {
      destroy_bitmap(m_screen_buff);
      m_screen_buff = NULL;
   }


   //
   if(m_layers != NULL) {
      m_layers->FreeAllLayers();
      delete m_layers;
      m_layers = NULL;
   }

   m_se->Exit();
   DELETE(m_se);
   DELETE(m_sp1);
   DELETE(m_sp2);

   return 0;
}


//
int cLvl_Ring01::Loop()
{
   uInt32 i;

   m_bkg->Update();

   for(i = 0; i < NUM_RING_LAYERS; ++i)
   {
      m_ring_layers[i]->Update();
   }

   m_fr_comm->Update();

   //
   m_sp1->PreUpdate();
   m_sp2->PreUpdate();

   m_zones->CheckZones();

   m_sp1->PostUpdate();
   m_sp2->PostUpdate();

   m_zones->UpdateZOrder();
   //

//
#ifdef DEBUG
   m_zones->show_zone = m_p1->m_zone_info->GetZone();
#endif


   m_ring_camera->Update();
   m_screen_x += m_ring_camera->GetShiftX();
   m_screen_y += m_ring_camera->GetShiftY();
   
   //
   if(m_comm_delay == 0)
   {
      if( m_commintator->Anim()->Done() )
      {
         // pick random time to wait to start next anim
         m_comm_delay = 30 + rand() % 100;

         // randomly select which animations sequence to play
         m_commintator->Anim()->Select( rand() % 3 );
         m_commintator->Anim()->Pause();
      }
   } else 
   if(m_comm_delay == 1)
   {
      m_commintator->Anim()->Play();
      m_comm_delay = 0;
   } else {
      --m_comm_delay;
   }
   //


   //
   m_ring_status_menu->Update();
   
   return 0;
}


//
int cLvl_Ring01::Draw()
{
   if(m_display == NULL) return 1;

   if( (m_layers != NULL) &&
       (m_screen_buff != NULL) )
   {
      rectfill(m_screen_buff, 0, 0, m_screen_w, m_screen_h, COLOR_BLACK);
      m_layers->Draw(m_screen_buff);

#ifdef DEBUG
      // show zone lines
      m_zones->DrawLines(m_screen_buff);
      //
#endif

      m_titan->CaptureBuffer(m_screen_buff);
   }

   m_display->Draw(m_screen_buff, m_screen_x, m_screen_y);
   m_ring_status_menu->Draw();

   return 0;
}


