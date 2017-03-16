let emoji: State.emoji = {
  key: "(alone)",
  src: "images/emoticons/alone.jpg",
  css: "big",
  title: "alone"
};

let emoticons: array State.emoji = [|
  {key: "(alone)", src: "images/emoticons/alone.jpg", css: "big", title: "alone"},
  {key: "(awwyea)", src: "images/emoticons/awwyea.jpg", css: "big", title: "awwyea"},
  {key: "(badass)", src: "images/emoticons/badass.png", css: "big", title: "badass"},
  {
    key: "(bitchplease)",
    src: "images/emoticons/bitchplease.jpg",
    css: "big",
    title: "bitchplease"
  },
  {key: "(cereal)", src: "images/emoticons/cereal.jpg", css: "big", title: "cereal"},
  {key: "(challenge)", src: "images/emoticons/challenge.jpg", css: "big", title: "challenge"},
  {key: "(fuckyeah)", src: "images/emoticons/fuckyeah.jpg", css: "big", title: "fuckyeah"},
  {key: "(gtfo)", src: "images/emoticons/gtfo.png", css: "big", title: "gtfo"},
  {key: "(ilied)", src: "images/emoticons/ilied.jpg", css: "big", title: "ilied"},
  {key: "(megusta)", src: "images/emoticons/megusta.jpg", css: "big", title: "megusta"},
  {key: "(notbad)", src: "images/emoticons/notbad.jpg", css: "big", title: "notbad"},
  {key: "(okay)", src: "images/emoticons/okay.jpg", css: "big", title: "okay"},
  {key: "(omgface)", src: "images/emoticons/omgface.jpg", css: "big", title: "omgface"},
  {key: "(pokerface)", src: "images/emoticons/pokerface.jpg", css: "big", title: "pokerface"},
  {key: "(problem)", src: "images/emoticons/trollface.jpg", css: "big", title: "problem"},
  {key: "(rageguy)", src: "images/emoticons/rageguy.jpg", css: "big", title: "rageguy"},
  {key: "(seriously)", src: "images/emoticons/seriously.jpg", css: "big", title: "seriously"},
  {key: "(sweetjesus)", src: "images/emoticons/sweetjesus.jpg", css: "big", title: "sweetjesus"},
  {key: "(trollface)", src: "images/emoticons/trollface.jpg", css: "big", title: "trollface"},
  {key: "(truestory)", src: "images/emoticons/truestory.png", css: "big", title: "truestory"},
  {key: "(youdontsay)", src: "images/emoticons/youdontsay.png", css: "big", title: "youdontsay"},
  {key: "(yuno)", src: "images/emoticons/yuno.jpg", css: "big", title: "yuno"},
  {key: ":(", src: "images/emoticons/sad.png", css: "small", title: "sad"},
  {key: "=(", src: "images/emoticons/sad.png", css: "small", title: "sad"},
  {key: ":)", src: "images/emoticons/happy.png", css: "small", title: "happy"},
  {key: "=)", src: "images/emoticons/happy.png", css: "small", title: "happy"},
  {key: ":p", src: "images/emoticons/tongue.png", css: "small", title: ":p"},
  {key: "=p", src: "images/emoticons/tongue.png", css: "small", title: "=p"},
  {key: ":bowtie:", src: "images/emoticons/emojis/bowtie.png", css: "small", title: "bowtie"},
  {key: ":smile:", src: "images/emoticons/emojis/smile.png", css: "small", title: "smile"},
  {
    key: ":laughing:",
    src: "images/emoticons/emojis/laughing.png",
    css: "small",
    title: "laughing"
  },
  {key: ":blush:", src: "images/emoticons/emojis/blush.png", css: "small", title: "blush"},
  {key: ":smiley:", src: "images/emoticons/emojis/smiley.png", css: "small", title: "smiley"},
  {key: ":relaxed:", src: "images/emoticons/emojis/relaxed.png", css: "small", title: "relaxed"},
  {key: ":smirk:", src: "images/emoticons/emojis/smirk.png", css: "small", title: "smirk"},
  {
    key: ":heart_eyes:",
    src: "images/emoticons/emojis/heart_eyes.png",
    css: "small",
    title: "heart_eyes"
  },
  {
    key: ":kissing_heart:",
    src: "images/emoticons/emojis/kissing_heart.png",
    css: "small",
    title: "kissing_heart"
  },
  {
    key: ":kissing_closed_eyes:",
    src: "images/emoticons/emojis/kissing_closed_eyes.png",
    css: "small",
    title: "kissing_closed_eyes"
  },
  {key: ":flushed:", src: "images/emoticons/emojis/flushed.png", css: "small", title: "flushed"},
  {
    key: ":relieved:",
    src: "images/emoticons/emojis/relieved.png",
    css: "small",
    title: "relieved"
  },
  {
    key: ":satisfied:",
    src: "images/emoticons/emojis/satisfied.png",
    css: "small",
    title: "satisfied"
  },
  {key: ":grin:", src: "images/emoticons/emojis/grin.png", css: "small", title: "grin"},
  {key: ":wink:", src: "images/emoticons/emojis/wink.png", css: "small", title: "wink"},
  {
    key: ":stuck_out_tongue_winking_eye:",
    src: "images/emoticons/emojis/stuck_out_tongue_winking_eye.png",
    css: "small",
    title: "stuck_out_tongue_winking_eye"
  },
  {
    key: ":stuck_out_tongue_closed_eyes:",
    src: "images/emoticons/emojis/stuck_out_tongue_closed_eyes.png",
    css: "small",
    title: "stuck_out_tongue_closed_eyes"
  },
  {
    key: ":grinning:",
    src: "images/emoticons/emojis/grinning.png",
    css: "small",
    title: "grinning"
  },
  {key: ":kissing:", src: "images/emoticons/emojis/kissing.png", css: "small", title: "kissing"},
  {
    key: ":kissing_smiling_eyes:",
    src: "images/emoticons/emojis/kissing_smiling_eyes.png",
    css: "small",
    title: "kissing_smiling_eyes"
  },
  {
    key: ":stuck_out_tongue:",
    src: "images/emoticons/emojis/stuck_out_tongue.png",
    css: "small",
    title: "stuck_out_tongue"
  },
  {
    key: ":sleeping:",
    src: "images/emoticons/emojis/sleeping.png",
    css: "small",
    title: "sleeping"
  },
  {key: ":worried:", src: "images/emoticons/emojis/worried.png", css: "small", title: "worried"},
  {
    key: ":frowning:",
    src: "images/emoticons/emojis/frowning.png",
    css: "small",
    title: "frowning"
  },
  {
    key: ":anguished:",
    src: "images/emoticons/emojis/anguished.png",
    css: "small",
    title: "anguished"
  },
  {
    key: ":open_mouth:",
    src: "images/emoticons/emojis/open_mouth.png",
    css: "small",
    title: "open_mouth"
  },
  {
    key: ":grimacing:",
    src: "images/emoticons/emojis/grimacing.png",
    css: "small",
    title: "grimacing"
  },
  {
    key: ":confused:",
    src: "images/emoticons/emojis/confused.png",
    css: "small",
    title: "confused"
  },
  {key: ":hushed:", src: "images/emoticons/emojis/hushed.png", css: "small", title: "hushed"},
  {
    key: ":expressionless:",
    src: "images/emoticons/emojis/expressionless.png",
    css: "small",
    title: "expressionless"
  },
  {
    key: ":unamused:",
    src: "images/emoticons/emojis/unamused.png",
    css: "small",
    title: "unamused"
  },
  {
    key: ":sweat_smile:",
    src: "images/emoticons/emojis/sweat_smile.png",
    css: "small",
    title: "sweat_smile"
  },
  {key: ":sweat:", src: "images/emoticons/emojis/sweat.png", css: "small", title: "sweat"},
  {
    key: ":disappointed_relieved:",
    src: "images/emoticons/emojis/disappointed_relieved.png",
    css: "small",
    title: "disappointed_relieved"
  },
  {key: ":weary:", src: "images/emoticons/emojis/weary.png", css: "small", title: "weary"},
  {key: ":pensive:", src: "images/emoticons/emojis/pensive.png", css: "small", title: "pensive"},
  {
    key: ":disappointed:",
    src: "images/emoticons/emojis/disappointed.png",
    css: "small",
    title: "disappointed"
  },
  {
    key: ":confounded:",
    src: "images/emoticons/emojis/confounded.png",
    css: "small",
    title: "confounded"
  },
  {key: ":fearful:", src: "images/emoticons/emojis/fearful.png", css: "small", title: "fearful"},
  {
    key: ":cold_sweat:",
    src: "images/emoticons/emojis/cold_sweat.png",
    css: "small",
    title: "cold_sweat"
  },
  {
    key: ":persevere:",
    src: "images/emoticons/emojis/persevere.png",
    css: "small",
    title: "persevere"
  },
  {key: ":cry:", src: "images/emoticons/emojis/cry.png", css: "small", title: "cry"},
  {key: ":sob:", src: "images/emoticons/emojis/sob.png", css: "small", title: "sob"},
  {key: ":joy:", src: "images/emoticons/emojis/joy.png", css: "small", title: "joy"},
  {
    key: ":astonished:",
    src: "images/emoticons/emojis/astonished.png",
    css: "small",
    title: "astonished"
  },
  {key: ":scream:", src: "images/emoticons/emojis/scream.png", css: "small", title: "scream"},
  {
    key: ":neckbeard:",
    src: "images/emoticons/emojis/neckbeard.png",
    css: "small",
    title: "neckbeard"
  },
  {
    key: ":tired_face:",
    src: "images/emoticons/emojis/tired_face.png",
    css: "small",
    title: "tired_face"
  },
  {key: ":angry:", src: "images/emoticons/emojis/angry.png", css: "small", title: "angry"},
  {key: ":rage:", src: "images/emoticons/emojis/rage.png", css: "small", title: "rage"},
  {key: ":triumph:", src: "images/emoticons/emojis/triumph.png", css: "small", title: "triumph"},
  {key: ":sleepy:", src: "images/emoticons/emojis/sleepy.png", css: "small", title: "sleepy"},
  {key: ":yum:", src: "images/emoticons/emojis/yum.png", css: "small", title: "yum"},
  {key: ":mask:", src: "images/emoticons/emojis/mask.png", css: "small", title: "mask"},
  {
    key: ":sunglasses:",
    src: "images/emoticons/emojis/sunglasses.png",
    css: "small",
    title: "sunglasses"
  },
  {
    key: ":dizzy_face:",
    src: "images/emoticons/emojis/dizzy_face.png",
    css: "small",
    title: "dizzy_face"
  },
  {key: ":imp:", src: "images/emoticons/emojis/imp.png", css: "small", title: "imp"},
  {
    key: ":smiling_imp:",
    src: "images/emoticons/emojis/smiling_imp.png",
    css: "small",
    title: "smiling_imp"
  },
  {
    key: ":neutral_face:",
    src: "images/emoticons/emojis/neutral_face.png",
    css: "small",
    title: "neutral_face"
  },
  {
    key: ":no_mouth:",
    src: "images/emoticons/emojis/no_mouth.png",
    css: "small",
    title: "no_mouth"
  },
  {
    key: ":innocent:",
    src: "images/emoticons/emojis/innocent.png",
    css: "small",
    title: "innocent"
  },
  {key: ":alien:", src: "images/emoticons/emojis/alien.png", css: "small", title: "alien"},
  {
    key: ":yellow_heart:",
    src: "images/emoticons/emojis/yellow_heart.png",
    css: "small",
    title: "yellow_heart"
  },
  {
    key: ":blue_heart:",
    src: "images/emoticons/emojis/blue_heart.png",
    css: "small",
    title: "blue_heart"
  },
  {
    key: ":purple_heart:",
    src: "images/emoticons/emojis/purple_heart.png",
    css: "small",
    title: "purple_heart"
  },
  {key: ":heart:", src: "images/emoticons/emojis/heart.png", css: "small", title: "heart"},
  {
    key: ":green_heart:",
    src: "images/emoticons/emojis/green_heart.png",
    css: "small",
    title: "green_heart"
  },
  {
    key: ":broken_heart:",
    src: "images/emoticons/emojis/broken_heart.png",
    css: "small",
    title: "broken_heart"
  },
  {
    key: ":heartbeat:",
    src: "images/emoticons/emojis/heartbeat.png",
    css: "small",
    title: "heartbeat"
  },
  {
    key: ":heartpulse:",
    src: "images/emoticons/emojis/heartpulse.png",
    css: "small",
    title: "heartpulse"
  },
  {
    key: ":two_hearts:",
    src: "images/emoticons/emojis/two_hearts.png",
    css: "small",
    title: "two_hearts"
  },
  {
    key: ":revolving_hearts:",
    src: "images/emoticons/emojis/revolving_hearts.png",
    css: "small",
    title: "revolving_hearts"
  },
  {key: ":cupid:", src: "images/emoticons/emojis/cupid.png", css: "small", title: "cupid"},
  {
    key: ":sparkling_heart:",
    src: "images/emoticons/emojis/sparkling_heart.png",
    css: "small",
    title: "sparkling_heart"
  },
  {
    key: ":sparkles:",
    src: "images/emoticons/emojis/sparkles.png",
    css: "small",
    title: "sparkles"
  },
  {key: ":star:", src: "images/emoticons/emojis/star.png", css: "small", title: "star"},
  {key: ":star2:", src: "images/emoticons/emojis/star2.png", css: "small", title: "star2"},
  {key: ":dizzy:", src: "images/emoticons/emojis/dizzy.png", css: "small", title: "dizzy"},
  {key: ":boom:", src: "images/emoticons/emojis/boom.png", css: "small", title: "boom"},
  {
    key: ":collision:",
    src: "images/emoticons/emojis/collision.png",
    css: "small",
    title: "collision"
  },
  {key: ":anger:", src: "images/emoticons/emojis/anger.png", css: "small", title: "anger"},
  {
    key: ":exclamation:",
    src: "images/emoticons/emojis/exclamation.png",
    css: "small",
    title: "exclamation"
  },
  {
    key: ":question:",
    src: "images/emoticons/emojis/question.png",
    css: "small",
    title: "question"
  },
  {
    key: ":grey_exclamation:",
    src: "images/emoticons/emojis/grey_exclamation.png",
    css: "small",
    title: "grey_exclamation"
  },
  {
    key: ":grey_question:",
    src: "images/emoticons/emojis/grey_question.png",
    css: "small",
    title: "grey_question"
  },
  {key: ":zzz:", src: "images/emoticons/emojis/zzz.png", css: "small", title: "zzz"},
  {key: ":dash:", src: "images/emoticons/emojis/dash.png", css: "small", title: "dash"},
  {
    key: ":sweat_drops:",
    src: "images/emoticons/emojis/sweat_drops.png",
    css: "small",
    title: "sweat_drops"
  },
  {key: ":notes:", src: "images/emoticons/emojis/notes.png", css: "small", title: "notes"},
  {
    key: ":musical_note:",
    src: "images/emoticons/emojis/musical_note.png",
    css: "small",
    title: "musical_note"
  },
  {key: ":fire:", src: "images/emoticons/emojis/fire.png", css: "small", title: "fire"},
  {key: ":hankey:", src: "images/emoticons/emojis/hankey.png", css: "small", title: "hankey"},
  {key: ":poop:", src: "images/emoticons/emojis/poop.png", css: "small", title: "poop"},
  {key: ":shit:", src: "images/emoticons/emojis/shit.png", css: "small", title: "shit"},
  {key: ":+1:", src: "images/emoticons/emojis/plus1.png", css: "small", title: "+1"},
  {
    key: ":thumbsup:",
    src: "images/emoticons/emojis/thumbsup.png",
    css: "small",
    title: "thumbsup"
  },
  {key: ":-1:", src: "images/emoticons/emojis/-1.png", css: "small", title: "-1"},
  {
    key: ":thumbsdown:",
    src: "images/emoticons/emojis/thumbsdown.png",
    css: "small",
    title: "thumbsdown"
  },
  {key: ":ok_hand:", src: "images/emoticons/emojis/ok_hand.png", css: "small", title: "ok_hand"},
  {key: ":punch:", src: "images/emoticons/emojis/punch.png", css: "small", title: "punch"},
  {
    key: ":facepunch:",
    src: "images/emoticons/emojis/facepunch.png",
    css: "small",
    title: "facepunch"
  },
  {key: ":fist:", src: "images/emoticons/emojis/fist.png", css: "small", title: "fist"},
  {key: ":v:", src: "images/emoticons/emojis/v.png", css: "small", title: "v"},
  {key: ":wave:", src: "images/emoticons/emojis/wave.png", css: "small", title: "wave"},
  {key: ":hand:", src: "images/emoticons/emojis/hand.png", css: "small", title: "hand"},
  {
    key: ":open_hands:",
    src: "images/emoticons/emojis/open_hands.png",
    css: "small",
    title: "open_hands"
  },
  {
    key: ":point_up:",
    src: "images/emoticons/emojis/point_up.png",
    css: "small",
    title: "point_up"
  },
  {
    key: ":point_down:",
    src: "images/emoticons/emojis/point_down.png",
    css: "small",
    title: "point_down"
  },
  {
    key: ":point_left:",
    src: "images/emoticons/emojis/point_left.png",
    css: "small",
    title: "point_left"
  },
  {
    key: ":point_right:",
    src: "images/emoticons/emojis/point_right.png",
    css: "small",
    title: "point_right"
  },
  {
    key: ":raised_hands:",
    src: "images/emoticons/emojis/raised_hands.png",
    css: "small",
    title: "raised_hands"
  },
  {key: ":pray:", src: "images/emoticons/emojis/pray.png", css: "small", title: "pray"},
  {
    key: ":point_up_2:",
    src: "images/emoticons/emojis/point_up_2.png",
    css: "small",
    title: "point_up_2"
  },
  {key: ":clap:", src: "images/emoticons/emojis/clap.png", css: "small", title: "clap"},
  {key: ":muscle:", src: "images/emoticons/emojis/muscle.png", css: "small", title: "muscle"},
  {key: ":metal:", src: "images/emoticons/emojis/metal.png", css: "small", title: "metal"},
  {key: ":fu:", src: "images/emoticons/emojis/fu.png", css: "small", title: "fu"},
  {key: ":walking:", src: "images/emoticons/emojis/walking.png", css: "small", title: "walking"},
  {key: ":runner:", src: "images/emoticons/emojis/runner.png", css: "small", title: "runner"},
  {key: ":running:", src: "images/emoticons/emojis/running.png", css: "small", title: "running"},
  {key: ":couple:", src: "images/emoticons/emojis/couple.png", css: "small", title: "couple"},
  {key: ":family:", src: "images/emoticons/emojis/family.png", css: "small", title: "family"},
  {
    key: ":two_men_holding_hands:",
    src: "images/emoticons/emojis/two_men_holding_hands.png",
    css: "small",
    title: "two_men_holding_hands"
  },
  {
    key: ":two_women_holding_hands:",
    src: "images/emoticons/emojis/two_women_holding_hands.png",
    css: "small",
    title: "two_women_holding_hands"
  },
  {key: ":dancer:", src: "images/emoticons/emojis/dancer.png", css: "small", title: "dancer"},
  {key: ":dancers:", src: "images/emoticons/emojis/dancers.png", css: "small", title: "dancers"},
  {
    key: ":ok_woman:",
    src: "images/emoticons/emojis/ok_woman.png",
    css: "small",
    title: "ok_woman"
  },
  {key: ":no_good:", src: "images/emoticons/emojis/no_good.png", css: "small", title: "no_good"},
  {
    key: ":information_desk_person:",
    src: "images/emoticons/emojis/information_desk_person.png",
    css: "small",
    title: "information_desk_person"
  },
  {
    key: ":raised_hand:",
    src: "images/emoticons/emojis/raised_hand.png",
    css: "small",
    title: "raised_hand"
  },
  {
    key: ":bride_with_veil:",
    src: "images/emoticons/emojis/bride_with_veil.png",
    css: "small",
    title: "bride_with_veil"
  },
  {
    key: ":person_with_pouting_face:",
    src: "images/emoticons/emojis/person_with_pouting_face.png",
    css: "small",
    title: "person_with_pouting_face"
  },
  {
    key: ":person_frowning:",
    src: "images/emoticons/emojis/person_frowning.png",
    css: "small",
    title: "person_frowning"
  },
  {key: ":bow:", src: "images/emoticons/emojis/bow.png", css: "small", title: "bow"},
  {
    key: ":couplekiss:",
    src: "images/emoticons/emojis/couplekiss.png",
    css: "small",
    title: "couplekiss"
  },
  {
    key: ":couple_with_heart:",
    src: "images/emoticons/emojis/couple_with_heart.png",
    css: "small",
    title: "couple_with_heart"
  },
  {key: ":massage:", src: "images/emoticons/emojis/massage.png", css: "small", title: "massage"},
  {key: ":haircut:", src: "images/emoticons/emojis/haircut.png", css: "small", title: "haircut"},
  {
    key: ":nail_care:",
    src: "images/emoticons/emojis/nail_care.png",
    css: "small",
    title: "nail_care"
  },
  {key: ":boy:", src: "images/emoticons/emojis/boy.png", css: "small", title: "boy"},
  {key: ":girl:", src: "images/emoticons/emojis/girl.png", css: "small", title: "girl"},
  {key: ":woman:", src: "images/emoticons/emojis/woman.png", css: "small", title: "woman"},
  {key: ":man:", src: "images/emoticons/emojis/man.png", css: "small", title: "man"},
  {key: ":baby:", src: "images/emoticons/emojis/baby.png", css: "small", title: "baby"},
  {
    key: ":older_woman:",
    src: "images/emoticons/emojis/older_woman.png",
    css: "small",
    title: "older_woman"
  },
  {
    key: ":older_man:",
    src: "images/emoticons/emojis/older_man.png",
    css: "small",
    title: "older_man"
  },
  {
    key: ":person_with_blond_hair:",
    src: "images/emoticons/emojis/person_with_blond_hair.png",
    css: "small",
    title: "person_with_blond_hair"
  },
  {
    key: ":man_with_gua_pi_mao:",
    src: "images/emoticons/emojis/man_with_gua_pi_mao.png",
    css: "small",
    title: "man_with_gua_pi_mao"
  },
  {
    key: ":man_with_turban:",
    src: "images/emoticons/emojis/man_with_turban.png",
    css: "small",
    title: "man_with_turban"
  },
  {
    key: ":construction_worker:",
    src: "images/emoticons/emojis/construction_worker.png",
    css: "small",
    title: "construction_worker"
  },
  {key: ":cop:", src: "images/emoticons/emojis/cop.png", css: "small", title: "cop"},
  {key: ":angel:", src: "images/emoticons/emojis/angel.png", css: "small", title: "angel"},
  {
    key: ":princess:",
    src: "images/emoticons/emojis/princess.png",
    css: "small",
    title: "princess"
  },
  {
    key: ":smiley_cat:",
    src: "images/emoticons/emojis/smiley_cat.png",
    css: "small",
    title: "smiley_cat"
  },
  {
    key: ":smile_cat:",
    src: "images/emoticons/emojis/smile_cat.png",
    css: "small",
    title: "smile_cat"
  },
  {
    key: ":heart_eyes_cat:",
    src: "images/emoticons/emojis/heart_eyes_cat.png",
    css: "small",
    title: "heart_eyes_cat"
  },
  {
    key: ":kissing_cat:",
    src: "images/emoticons/emojis/kissing_cat.png",
    css: "small",
    title: "kissing_cat"
  },
  {
    key: ":smirk_cat:",
    src: "images/emoticons/emojis/smirk_cat.png",
    css: "small",
    title: "smirk_cat"
  },
  {
    key: ":scream_cat:",
    src: "images/emoticons/emojis/scream_cat.png",
    css: "small",
    title: "scream_cat"
  },
  {
    key: ":crying_cat_face:",
    src: "images/emoticons/emojis/crying_cat_face.png",
    css: "small",
    title: "crying_cat_face"
  },
  {key: ":joy_cat:", src: "images/emoticons/emojis/joy_cat.png", css: "small", title: "joy_cat"},
  {
    key: ":pouting_cat:",
    src: "images/emoticons/emojis/pouting_cat.png",
    css: "small",
    title: "pouting_cat"
  },
  {
    key: ":japanese_ogre:",
    src: "images/emoticons/emojis/japanese_ogre.png",
    css: "small",
    title: "japanese_ogre"
  },
  {
    key: ":japanese_goblin:",
    src: "images/emoticons/emojis/japanese_goblin.png",
    css: "small",
    title: "japanese_goblin"
  },
  {
    key: ":see_no_evil:",
    src: "images/emoticons/emojis/see_no_evil.png",
    css: "small",
    title: "see_no_evil"
  },
  {
    key: ":hear_no_evil:",
    src: "images/emoticons/emojis/hear_no_evil.png",
    css: "small",
    title: "hear_no_evil"
  },
  {
    key: ":speak_no_evil:",
    src: "images/emoticons/emojis/speak_no_evil.png",
    css: "small",
    title: "speak_no_evil"
  },
  {
    key: ":guardsman:",
    src: "images/emoticons/emojis/guardsman.png",
    css: "small",
    title: "guardsman"
  },
  {key: ":skull:", src: "images/emoticons/emojis/skull.png", css: "small", title: "skull"},
  {key: ":feet:", src: "images/emoticons/emojis/feet.png", css: "small", title: "feet"},
  {key: ":lips:", src: "images/emoticons/emojis/lips.png", css: "small", title: "lips"},
  {key: ":kiss:", src: "images/emoticons/emojis/kiss.png", css: "small", title: "kiss"},
  {key: ":droplet:", src: "images/emoticons/emojis/droplet.png", css: "small", title: "droplet"},
  {key: ":ear:", src: "images/emoticons/emojis/ear.png", css: "small", title: "ear"},
  {key: ":eyes:", src: "images/emoticons/emojis/eyes.png", css: "small", title: "eyes"},
  {key: ":nose:", src: "images/emoticons/emojis/nose.png", css: "small", title: "nose"},
  {key: ":tongue:", src: "images/emoticons/emojis/tongue.png", css: "small", title: "tongue"},
  {
    key: ":love_letter:",
    src: "images/emoticons/emojis/love_letter.png",
    css: "small",
    title: "love_letter"
  },
  {
    key: ":bust_in_silhouette:",
    src: "images/emoticons/emojis/bust_in_silhouette.png",
    css: "small",
    title: "bust_in_silhouette"
  },
  {
    key: ":busts_in_silhouette:",
    src: "images/emoticons/emojis/busts_in_silhouette.png",
    css: "small",
    title: "busts_in_silhouette"
  },
  {
    key: ":speech_balloon:",
    src: "images/emoticons/emojis/speech_balloon.png",
    css: "small",
    title: "speech_balloon"
  },
  {
    key: ":thought_balloon:",
    src: "images/emoticons/emojis/thought_balloon.png",
    css: "small",
    title: "thought_balloon"
  },
  {
    key: ":feelsgood:",
    src: "images/emoticons/emojis/feelsgood.png",
    css: "small",
    title: "feelsgood"
  },
  {
    key: ":finnadie:",
    src: "images/emoticons/emojis/finnadie.png",
    css: "small",
    title: "finnadie"
  },
  {
    key: ":goberserk:",
    src: "images/emoticons/emojis/goberserk.png",
    css: "small",
    title: "goberserk"
  },
  {key: ":godmode:", src: "images/emoticons/emojis/godmode.png", css: "small", title: "godmode"},
  {
    key: ":hurtrealbad:",
    src: "images/emoticons/emojis/hurtrealbad.png",
    css: "small",
    title: "hurtrealbad"
  },
  {key: ":rage1:", src: "images/emoticons/emojis/rage1.png", css: "small", title: "rage1"},
  {key: ":rage2:", src: "images/emoticons/emojis/rage2.png", css: "small", title: "rage2"},
  {key: ":rage3:", src: "images/emoticons/emojis/rage3.png", css: "small", title: "rage3"},
  {key: ":rage4:", src: "images/emoticons/emojis/rage4.png", css: "small", title: "rage4"},
  {key: ":suspect:", src: "images/emoticons/emojis/suspect.png", css: "small", title: "suspect"},
  {
    key: ":trollface:",
    src: "images/emoticons/emojis/trollface.png",
    css: "small",
    title: "trollface"
  },
  {key: ":sunny:", src: "images/emoticons/emojis/sunny.png", css: "small", title: "sunny"},
  {
    key: ":umbrella:",
    src: "images/emoticons/emojis/umbrella.png",
    css: "small",
    title: "umbrella"
  },
  {key: ":cloud:", src: "images/emoticons/emojis/cloud.png", css: "small", title: "cloud"},
  {
    key: ":snowflake:",
    src: "images/emoticons/emojis/snowflake.png",
    css: "small",
    title: "snowflake"
  },
  {key: ":snowman:", src: "images/emoticons/emojis/snowman.png", css: "small", title: "snowman"},
  {key: ":zap:", src: "images/emoticons/emojis/zap.png", css: "small", title: "zap"},
  {key: ":cyclone:", src: "images/emoticons/emojis/cyclone.png", css: "small", title: "cyclone"},
  {key: ":foggy:", src: "images/emoticons/emojis/foggy.png", css: "small", title: "foggy"},
  {key: ":ocean:", src: "images/emoticons/emojis/ocean.png", css: "small", title: "ocean"},
  {key: ":cat:", src: "images/emoticons/emojis/cat.png", css: "small", title: "cat"},
  {key: ":dog:", src: "images/emoticons/emojis/dog.png", css: "small", title: "dog"},
  {key: ":mouse:", src: "images/emoticons/emojis/mouse.png", css: "small", title: "mouse"},
  {key: ":hamster:", src: "images/emoticons/emojis/hamster.png", css: "small", title: "hamster"},
  {key: ":rabbit:", src: "images/emoticons/emojis/rabbit.png", css: "small", title: "rabbit"},
  {key: ":wolf:", src: "images/emoticons/emojis/wolf.png", css: "small", title: "wolf"},
  {key: ":frog:", src: "images/emoticons/emojis/frog.png", css: "small", title: "frog"},
  {key: ":tiger:", src: "images/emoticons/emojis/tiger.png", css: "small", title: "tiger"},
  {key: ":koala:", src: "images/emoticons/emojis/koala.png", css: "small", title: "koala"},
  {key: ":bear:", src: "images/emoticons/emojis/bear.png", css: "small", title: "bear"},
  {key: ":pig:", src: "images/emoticons/emojis/pig.png", css: "small", title: "pig"},
  {
    key: ":pig_nose:",
    src: "images/emoticons/emojis/pig_nose.png",
    css: "small",
    title: "pig_nose"
  },
  {key: ":cow:", src: "images/emoticons/emojis/cow.png", css: "small", title: "cow"},
  {key: ":boar:", src: "images/emoticons/emojis/boar.png", css: "small", title: "boar"},
  {
    key: ":monkey_face:",
    src: "images/emoticons/emojis/monkey_face.png",
    css: "small",
    title: "monkey_face"
  },
  {key: ":monkey:", src: "images/emoticons/emojis/monkey.png", css: "small", title: "monkey"},
  {key: ":horse:", src: "images/emoticons/emojis/horse.png", css: "small", title: "horse"},
  {
    key: ":racehorse:",
    src: "images/emoticons/emojis/racehorse.png",
    css: "small",
    title: "racehorse"
  },
  {key: ":camel:", src: "images/emoticons/emojis/camel.png", css: "small", title: "camel"},
  {key: ":sheep:", src: "images/emoticons/emojis/sheep.png", css: "small", title: "sheep"},
  {
    key: ":elephant:",
    src: "images/emoticons/emojis/elephant.png",
    css: "small",
    title: "elephant"
  },
  {
    key: ":panda_face:",
    src: "images/emoticons/emojis/panda_face.png",
    css: "small",
    title: "panda_face"
  },
  {key: ":snake:", src: "images/emoticons/emojis/snake.png", css: "small", title: "snake"},
  {key: ":bird:", src: "images/emoticons/emojis/bird.png", css: "small", title: "bird"},
  {
    key: ":baby_chick:",
    src: "images/emoticons/emojis/baby_chick.png",
    css: "small",
    title: "baby_chick"
  },
  {
    key: ":hatched_chick:",
    src: "images/emoticons/emojis/hatched_chick.png",
    css: "small",
    title: "hatched_chick"
  },
  {
    key: ":hatching_chick:",
    src: "images/emoticons/emojis/hatching_chick.png",
    css: "small",
    title: "hatching_chick"
  },
  {key: ":chicken:", src: "images/emoticons/emojis/chicken.png", css: "small", title: "chicken"},
  {key: ":penguin:", src: "images/emoticons/emojis/penguin.png", css: "small", title: "penguin"},
  {key: ":turtle:", src: "images/emoticons/emojis/turtle.png", css: "small", title: "turtle"},
  {key: ":bug:", src: "images/emoticons/emojis/bug.png", css: "small", title: "bug"},
  {
    key: ":honeybee:",
    src: "images/emoticons/emojis/honeybee.png",
    css: "small",
    title: "honeybee"
  },
  {key: ":ant:", src: "images/emoticons/emojis/ant.png", css: "small", title: "ant"},
  {key: ":beetle:", src: "images/emoticons/emojis/beetle.png", css: "small", title: "beetle"},
  {key: ":snail:", src: "images/emoticons/emojis/snail.png", css: "small", title: "snail"},
  {key: ":octopus:", src: "images/emoticons/emojis/octopus.png", css: "small", title: "octopus"},
  {
    key: ":tropical_fish:",
    src: "images/emoticons/emojis/tropical_fish.png",
    css: "small",
    title: "tropical_fish"
  },
  {key: ":fish:", src: "images/emoticons/emojis/fish.png", css: "small", title: "fish"},
  {key: ":whale:", src: "images/emoticons/emojis/whale.png", css: "small", title: "whale"},
  {key: ":whale2:", src: "images/emoticons/emojis/whale2.png", css: "small", title: "whale2"},
  {key: ":dolphin:", src: "images/emoticons/emojis/dolphin.png", css: "small", title: "dolphin"},
  {key: ":cow2:", src: "images/emoticons/emojis/cow2.png", css: "small", title: "cow2"},
  {key: ":ram:", src: "images/emoticons/emojis/ram.png", css: "small", title: "ram"},
  {key: ":rat:", src: "images/emoticons/emojis/rat.png", css: "small", title: "rat"},
  {
    key: ":water_buffalo:",
    src: "images/emoticons/emojis/water_buffalo.png",
    css: "small",
    title: "water_buffalo"
  },
  {key: ":tiger2:", src: "images/emoticons/emojis/tiger2.png", css: "small", title: "tiger2"},
  {key: ":rabbit2:", src: "images/emoticons/emojis/rabbit2.png", css: "small", title: "rabbit2"},
  {key: ":dragon:", src: "images/emoticons/emojis/dragon.png", css: "small", title: "dragon"},
  {key: ":goat:", src: "images/emoticons/emojis/goat.png", css: "small", title: "goat"},
  {key: ":rooster:", src: "images/emoticons/emojis/rooster.png", css: "small", title: "rooster"},
  {key: ":dog2:", src: "images/emoticons/emojis/dog2.png", css: "small", title: "dog2"},
  {key: ":pig2:", src: "images/emoticons/emojis/pig2.png", css: "small", title: "pig2"},
  {key: ":mouse2:", src: "images/emoticons/emojis/mouse2.png", css: "small", title: "mouse2"},
  {key: ":ox:", src: "images/emoticons/emojis/ox.png", css: "small", title: "ox"},
  {
    key: ":dragon_face:",
    src: "images/emoticons/emojis/dragon_face.png",
    css: "small",
    title: "dragon_face"
  },
  {
    key: ":blowfish:",
    src: "images/emoticons/emojis/blowfish.png",
    css: "small",
    title: "blowfish"
  },
  {
    key: ":crocodile:",
    src: "images/emoticons/emojis/crocodile.png",
    css: "small",
    title: "crocodile"
  },
  {
    key: ":dromedary_camel:",
    src: "images/emoticons/emojis/dromedary_camel.png",
    css: "small",
    title: "dromedary_camel"
  },
  {key: ":leopard:", src: "images/emoticons/emojis/leopard.png", css: "small", title: "leopard"},
  {key: ":cat2:", src: "images/emoticons/emojis/cat2.png", css: "small", title: "cat2"},
  {key: ":poodle:", src: "images/emoticons/emojis/poodle.png", css: "small", title: "poodle"},
  {
    key: ":paw_prints:",
    src: "images/emoticons/emojis/paw_prints.png",
    css: "small",
    title: "paw_prints"
  },
  {key: ":bouquet:", src: "images/emoticons/emojis/bouquet.png", css: "small", title: "bouquet"},
  {
    key: ":cherry_blossom:",
    src: "images/emoticons/emojis/cherry_blossom.png",
    css: "small",
    title: "cherry_blossom"
  },
  {key: ":tulip:", src: "images/emoticons/emojis/tulip.png", css: "small", title: "tulip"},
  {
    key: ":four_leaf_clover:",
    src: "images/emoticons/emojis/four_leaf_clover.png",
    css: "small",
    title: "four_leaf_clover"
  },
  {key: ":rose:", src: "images/emoticons/emojis/rose.png", css: "small", title: "rose"},
  {
    key: ":sunflower:",
    src: "images/emoticons/emojis/sunflower.png",
    css: "small",
    title: "sunflower"
  },
  {
    key: ":hibiscus:",
    src: "images/emoticons/emojis/hibiscus.png",
    css: "small",
    title: "hibiscus"
  },
  {
    key: ":maple_leaf:",
    src: "images/emoticons/emojis/maple_leaf.png",
    css: "small",
    title: "maple_leaf"
  },
  {key: ":leaves:", src: "images/emoticons/emojis/leaves.png", css: "small", title: "leaves"},
  {
    key: ":fallen_leaf:",
    src: "images/emoticons/emojis/fallen_leaf.png",
    css: "small",
    title: "fallen_leaf"
  },
  {key: ":herb:", src: "images/emoticons/emojis/herb.png", css: "small", title: "herb"},
  {
    key: ":mushroom:",
    src: "images/emoticons/emojis/mushroom.png",
    css: "small",
    title: "mushroom"
  },
  {key: ":cactus:", src: "images/emoticons/emojis/cactus.png", css: "small", title: "cactus"},
  {
    key: ":palm_tree:",
    src: "images/emoticons/emojis/palm_tree.png",
    css: "small",
    title: "palm_tree"
  },
  {
    key: ":evergreen_tree:",
    src: "images/emoticons/emojis/evergreen_tree.png",
    css: "small",
    title: "evergreen_tree"
  },
  {
    key: ":deciduous_tree:",
    src: "images/emoticons/emojis/deciduous_tree.png",
    css: "small",
    title: "deciduous_tree"
  },
  {
    key: ":chestnut:",
    src: "images/emoticons/emojis/chestnut.png",
    css: "small",
    title: "chestnut"
  },
  {
    key: ":seedling:",
    src: "images/emoticons/emojis/seedling.png",
    css: "small",
    title: "seedling"
  },
  {key: ":blossom:", src: "images/emoticons/emojis/blossom.png", css: "small", title: "blossom"},
  {
    key: ":ear_of_rice:",
    src: "images/emoticons/emojis/ear_of_rice.png",
    css: "small",
    title: "ear_of_rice"
  },
  {key: ":shell:", src: "images/emoticons/emojis/shell.png", css: "small", title: "shell"},
  {
    key: ":globe_with_meridians:",
    src: "images/emoticons/emojis/globe_with_meridians.png",
    css: "small",
    title: "globe_with_meridians"
  },
  {
    key: ":sun_with_face:",
    src: "images/emoticons/emojis/sun_with_face.png",
    css: "small",
    title: "sun_with_face"
  },
  {
    key: ":full_moon_with_face:",
    src: "images/emoticons/emojis/full_moon_with_face.png",
    css: "small",
    title: "full_moon_with_face"
  },
  {
    key: ":new_moon_with_face:",
    src: "images/emoticons/emojis/new_moon_with_face.png",
    css: "small",
    title: "new_moon_with_face"
  },
  {
    key: ":new_moon:",
    src: "images/emoticons/emojis/new_moon.png",
    css: "small",
    title: "new_moon"
  },
  {
    key: ":waxing_crescent_moon:",
    src: "images/emoticons/emojis/waxing_crescent_moon.png",
    css: "small",
    title: "waxing_crescent_moon"
  },
  {
    key: ":first_quarter_moon:",
    src: "images/emoticons/emojis/first_quarter_moon.png",
    css: "small",
    title: "first_quarter_moon"
  },
  {
    key: ":waxing_gibbous_moon:",
    src: "images/emoticons/emojis/waxing_gibbous_moon.png",
    css: "small",
    title: "waxing_gibbous_moon"
  },
  {
    key: ":full_moon:",
    src: "images/emoticons/emojis/full_moon.png",
    css: "small",
    title: "full_moon"
  },
  {
    key: ":waning_gibbous_moon:",
    src: "images/emoticons/emojis/waning_gibbous_moon.png",
    css: "small",
    title: "waning_gibbous_moon"
  },
  {
    key: ":last_quarter_moon:",
    src: "images/emoticons/emojis/last_quarter_moon.png",
    css: "small",
    title: "last_quarter_moon"
  },
  {
    key: ":waning_crescent_moon:",
    src: "images/emoticons/emojis/waning_crescent_moon.png",
    css: "small",
    title: "waning_crescent_moon"
  },
  {
    key: ":last_quarter_moon_with_face:",
    src: "images/emoticons/emojis/last_quarter_moon_with_face.png",
    css: "small",
    title: "last_quarter_moon_with_face"
  },
  {
    key: ":first_quarter_moon_with_face:",
    src: "images/emoticons/emojis/first_quarter_moon_with_face.png",
    css: "small",
    title: "first_quarter_moon_with_face"
  },
  {key: ":moon:", src: "images/emoticons/emojis/moon.png", css: "small", title: "moon"},
  {
    key: ":earth_africa:",
    src: "images/emoticons/emojis/earth_africa.png",
    css: "small",
    title: "earth_africa"
  },
  {
    key: ":earth_americas:",
    src: "images/emoticons/emojis/earth_americas.png",
    css: "small",
    title: "earth_americas"
  },
  {
    key: ":earth_asia:",
    src: "images/emoticons/emojis/earth_asia.png",
    css: "small",
    title: "earth_asia"
  },
  {key: ":volcano:", src: "images/emoticons/emojis/volcano.png", css: "small", title: "volcano"},
  {
    key: ":milky_way:",
    src: "images/emoticons/emojis/milky_way.png",
    css: "small",
    title: "milky_way"
  },
  {
    key: ":partly_sunny:",
    src: "images/emoticons/emojis/partly_sunny.png",
    css: "small",
    title: "partly_sunny"
  },
  {key: ":octocat:", src: "images/emoticons/emojis/octocat.png", css: "small", title: "octocat"},
  {
    key: ":squirrel:",
    src: "images/emoticons/emojis/squirrel.png",
    css: "small",
    title: "squirrel"
  },
  {key: ":bamboo:", src: "images/emoticons/emojis/bamboo.png", css: "small", title: "bamboo"},
  {
    key: ":gift_heart:",
    src: "images/emoticons/emojis/gift_heart.png",
    css: "small",
    title: "gift_heart"
  },
  {key: ":dolls:", src: "images/emoticons/emojis/dolls.png", css: "small", title: "dolls"},
  {
    key: ":school_satchel:",
    src: "images/emoticons/emojis/school_satchel.png",
    css: "small",
    title: "school_satchel"
  },
  {
    key: ":mortar_board:",
    src: "images/emoticons/emojis/mortar_board.png",
    css: "small",
    title: "mortar_board"
  },
  {key: ":flags:", src: "images/emoticons/emojis/flags.png", css: "small", title: "flags"},
  {
    key: ":fireworks:",
    src: "images/emoticons/emojis/fireworks.png",
    css: "small",
    title: "fireworks"
  },
  {
    key: ":sparkler:",
    src: "images/emoticons/emojis/sparkler.png",
    css: "small",
    title: "sparkler"
  },
  {
    key: ":wind_chime:",
    src: "images/emoticons/emojis/wind_chime.png",
    css: "small",
    title: "wind_chime"
  },
  {
    key: ":rice_scene:",
    src: "images/emoticons/emojis/rice_scene.png",
    css: "small",
    title: "rice_scene"
  },
  {
    key: ":jack_o_lantern:",
    src: "images/emoticons/emojis/jack_o_lantern.png",
    css: "small",
    title: "jack_o_lantern"
  },
  {key: ":ghost:", src: "images/emoticons/emojis/ghost.png", css: "small", title: "ghost"},
  {key: ":santa:", src: "images/emoticons/emojis/santa.png", css: "small", title: "santa"},
  {
    key: ":christmas_tree:",
    src: "images/emoticons/emojis/christmas_tree.png",
    css: "small",
    title: "christmas_tree"
  },
  {key: ":gift:", src: "images/emoticons/emojis/gift.png", css: "small", title: "gift"},
  {key: ":bell:", src: "images/emoticons/emojis/bell.png", css: "small", title: "bell"},
  {key: ":no_bell:", src: "images/emoticons/emojis/no_bell.png", css: "small", title: "no_bell"},
  {
    key: ":tanabata_tree:",
    src: "images/emoticons/emojis/tanabata_tree.png",
    css: "small",
    title: "tanabata_tree"
  },
  {key: ":tada:", src: "images/emoticons/emojis/tada.png", css: "small", title: "tada"},
  {
    key: ":confetti_ball:",
    src: "images/emoticons/emojis/confetti_ball.png",
    css: "small",
    title: "confetti_ball"
  },
  {key: ":balloon:", src: "images/emoticons/emojis/balloon.png", css: "small", title: "balloon"},
  {
    key: ":crystal_ball:",
    src: "images/emoticons/emojis/crystal_ball.png",
    css: "small",
    title: "crystal_ball"
  },
  {key: ":cd:", src: "images/emoticons/emojis/cd.png", css: "small", title: "cd"},
  {key: ":dvd:", src: "images/emoticons/emojis/dvd.png", css: "small", title: "dvd"},
  {
    key: ":floppy_disk:",
    src: "images/emoticons/emojis/floppy_disk.png",
    css: "small",
    title: "floppy_disk"
  },
  {key: ":camera:", src: "images/emoticons/emojis/camera.png", css: "small", title: "camera"},
  {
    key: ":video_camera:",
    src: "images/emoticons/emojis/video_camera.png",
    css: "small",
    title: "video_camera"
  },
  {
    key: ":movie_camera:",
    src: "images/emoticons/emojis/movie_camera.png",
    css: "small",
    title: "movie_camera"
  },
  {
    key: ":computer:",
    src: "images/emoticons/emojis/computer.png",
    css: "small",
    title: "computer"
  },
  {key: ":tv:", src: "images/emoticons/emojis/tv.png", css: "small", title: "tv"},
  {key: ":iphone:", src: "images/emoticons/emojis/iphone.png", css: "small", title: "iphone"},
  {key: ":phone:", src: "images/emoticons/emojis/phone.png", css: "small", title: "phone"},
  {
    key: ":telephone:",
    src: "images/emoticons/emojis/telephone.png",
    css: "small",
    title: "telephone"
  },
  {
    key: ":telephone_receiver:",
    src: "images/emoticons/emojis/telephone_receiver.png",
    css: "small",
    title: "telephone_receiver"
  },
  {key: ":pager:", src: "images/emoticons/emojis/pager.png", css: "small", title: "pager"},
  {key: ":fax:", src: "images/emoticons/emojis/fax.png", css: "small", title: "fax"},
  {
    key: ":minidisc:",
    src: "images/emoticons/emojis/minidisc.png",
    css: "small",
    title: "minidisc"
  },
  {key: ":vhs:", src: "images/emoticons/emojis/vhs.png", css: "small", title: "vhs"},
  {key: ":sound:", src: "images/emoticons/emojis/sound.png", css: "small", title: "sound"},
  {key: ":speaker:", src: "images/emoticons/emojis/speaker.png", css: "small", title: "speaker"},
  {key: ":mute:", src: "images/emoticons/emojis/mute.png", css: "small", title: "mute"},
  {
    key: ":loudspeaker:",
    src: "images/emoticons/emojis/loudspeaker.png",
    css: "small",
    title: "loudspeaker"
  },
  {key: ":mega:", src: "images/emoticons/emojis/mega.png", css: "small", title: "mega"},
  {
    key: ":hourglass:",
    src: "images/emoticons/emojis/hourglass.png",
    css: "small",
    title: "hourglass"
  },
  {
    key: ":hourglass_flowing_sand:",
    src: "images/emoticons/emojis/hourglass_flowing_sand.png",
    css: "small",
    title: "hourglass_flowing_sand"
  },
  {
    key: ":alarm_clock:",
    src: "images/emoticons/emojis/alarm_clock.png",
    css: "small",
    title: "alarm_clock"
  },
  {key: ":watch:", src: "images/emoticons/emojis/watch.png", css: "small", title: "watch"},
  {key: ":radio:", src: "images/emoticons/emojis/radio.png", css: "small", title: "radio"},
  {
    key: ":satellite:",
    src: "images/emoticons/emojis/satellite.png",
    css: "small",
    title: "satellite"
  },
  {key: ":loop:", src: "images/emoticons/emojis/loop.png", css: "small", title: "loop"},
  {key: ":mag:", src: "images/emoticons/emojis/mag.png", css: "small", title: "mag"},
  {
    key: ":mag_right:",
    src: "images/emoticons/emojis/mag_right.png",
    css: "small",
    title: "mag_right"
  },
  {key: ":unlock:", src: "images/emoticons/emojis/unlock.png", css: "small", title: "unlock"},
  {key: ":lock:", src: "images/emoticons/emojis/lock.png", css: "small", title: "lock"},
  {
    key: ":lock_with_ink_pen:",
    src: "images/emoticons/emojis/lock_with_ink_pen.png",
    css: "small",
    title: "lock_with_ink_pen"
  },
  {
    key: ":closed_lock_with_key:",
    src: "images/emoticons/emojis/closed_lock_with_key.png",
    css: "small",
    title: "closed_lock_with_key"
  },
  {key: ":key:", src: "images/emoticons/emojis/key.png", css: "small", title: "key"},
  {key: ":bulb:", src: "images/emoticons/emojis/bulb.png", css: "small", title: "bulb"},
  {
    key: ":flashlight:",
    src: "images/emoticons/emojis/flashlight.png",
    css: "small",
    title: "flashlight"
  },
  {
    key: ":high_brightness:",
    src: "images/emoticons/emojis/high_brightness.png",
    css: "small",
    title: "high_brightness"
  },
  {
    key: ":low_brightness:",
    src: "images/emoticons/emojis/low_brightness.png",
    css: "small",
    title: "low_brightness"
  },
  {
    key: ":electric_plug:",
    src: "images/emoticons/emojis/electric_plug.png",
    css: "small",
    title: "electric_plug"
  },
  {key: ":battery:", src: "images/emoticons/emojis/battery.png", css: "small", title: "battery"},
  {key: ":calling:", src: "images/emoticons/emojis/calling.png", css: "small", title: "calling"},
  {key: ":email:", src: "images/emoticons/emojis/email.png", css: "small", title: "email"},
  {key: ":mailbox:", src: "images/emoticons/emojis/mailbox.png", css: "small", title: "mailbox"},
  {key: ":postbox:", src: "images/emoticons/emojis/postbox.png", css: "small", title: "postbox"},
  {key: ":bath:", src: "images/emoticons/emojis/bath.png", css: "small", title: "bath"},
  {key: ":bathtub:", src: "images/emoticons/emojis/bathtub.png", css: "small", title: "bathtub"},
  {key: ":shower:", src: "images/emoticons/emojis/shower.png", css: "small", title: "shower"},
  {key: ":toilet:", src: "images/emoticons/emojis/toilet.png", css: "small", title: "toilet"},
  {key: ":wrench:", src: "images/emoticons/emojis/wrench.png", css: "small", title: "wrench"},
  {
    key: ":nut_and_bolt:",
    src: "images/emoticons/emojis/nut_and_bolt.png",
    css: "small",
    title: "nut_and_bolt"
  },
  {key: ":hammer:", src: "images/emoticons/emojis/hammer.png", css: "small", title: "hammer"},
  {key: ":seat:", src: "images/emoticons/emojis/seat.png", css: "small", title: "seat"},
  {
    key: ":moneybag:",
    src: "images/emoticons/emojis/moneybag.png",
    css: "small",
    title: "moneybag"
  },
  {key: ":yen:", src: "images/emoticons/emojis/yen.png", css: "small", title: "yen"},
  {key: ":dollar:", src: "images/emoticons/emojis/dollar.png", css: "small", title: "dollar"},
  {key: ":pound:", src: "images/emoticons/emojis/pound.png", css: "small", title: "pound"},
  {key: ":euro:", src: "images/emoticons/emojis/euro.png", css: "small", title: "euro"},
  {
    key: ":credit_card:",
    src: "images/emoticons/emojis/credit_card.png",
    css: "small",
    title: "credit_card"
  },
  {
    key: ":money_with_wings:",
    src: "images/emoticons/emojis/money_with_wings.png",
    css: "small",
    title: "money_with_wings"
  },
  {key: ":e-mail:", src: "images/emoticons/emojis/e-mail.png", css: "small", title: "e-mail"},
  {
    key: ":inbox_tray:",
    src: "images/emoticons/emojis/inbox_tray.png",
    css: "small",
    title: "inbox_tray"
  },
  {
    key: ":outbox_tray:",
    src: "images/emoticons/emojis/outbox_tray.png",
    css: "small",
    title: "outbox_tray"
  },
  {
    key: ":envelope:",
    src: "images/emoticons/emojis/envelope.png",
    css: "small",
    title: "envelope"
  },
  {
    key: ":incoming_envelope:",
    src: "images/emoticons/emojis/incoming_envelope.png",
    css: "small",
    title: "incoming_envelope"
  },
  {
    key: ":postal_horn:",
    src: "images/emoticons/emojis/postal_horn.png",
    css: "small",
    title: "postal_horn"
  },
  {
    key: ":mailbox_closed:",
    src: "images/emoticons/emojis/mailbox_closed.png",
    css: "small",
    title: "mailbox_closed"
  },
  {
    key: ":mailbox_with_mail:",
    src: "images/emoticons/emojis/mailbox_with_mail.png",
    css: "small",
    title: "mailbox_with_mail"
  },
  {
    key: ":mailbox_with_no_mail:",
    src: "images/emoticons/emojis/mailbox_with_no_mail.png",
    css: "small",
    title: "mailbox_with_no_mail"
  },
  {key: ":door:", src: "images/emoticons/emojis/door.png", css: "small", title: "door"},
  {key: ":smoking:", src: "images/emoticons/emojis/smoking.png", css: "small", title: "smoking"},
  {key: ":bomb:", src: "images/emoticons/emojis/bomb.png", css: "small", title: "bomb"},
  {key: ":gun:", src: "images/emoticons/emojis/gun.png", css: "small", title: "gun"},
  {key: ":hocho:", src: "images/emoticons/emojis/hocho.png", css: "small", title: "hocho"},
  {key: ":pill:", src: "images/emoticons/emojis/pill.png", css: "small", title: "pill"},
  {key: ":syringe:", src: "images/emoticons/emojis/syringe.png", css: "small", title: "syringe"},
  {
    key: ":page_facing_up:",
    src: "images/emoticons/emojis/page_facing_up.png",
    css: "small",
    title: "page_facing_up"
  },
  {
    key: ":page_with_curl:",
    src: "images/emoticons/emojis/page_with_curl.png",
    css: "small",
    title: "page_with_curl"
  },
  {
    key: ":bookmark_tabs:",
    src: "images/emoticons/emojis/bookmark_tabs.png",
    css: "small",
    title: "bookmark_tabs"
  },
  {
    key: ":bar_chart:",
    src: "images/emoticons/emojis/bar_chart.png",
    css: "small",
    title: "bar_chart"
  },
  {
    key: ":chart_with_upwards_trend:",
    src: "images/emoticons/emojis/chart_with_upwards_trend.png",
    css: "small",
    title: "chart_with_upwards_trend"
  },
  {
    key: ":chart_with_downwards_trend:",
    src: "images/emoticons/emojis/chart_with_downwards_trend.png",
    css: "small",
    title: "chart_with_downwards_trend"
  },
  {key: ":scroll:", src: "images/emoticons/emojis/scroll.png", css: "small", title: "scroll"},
  {
    key: ":clipboard:",
    src: "images/emoticons/emojis/clipboard.png",
    css: "small",
    title: "clipboard"
  },
  {
    key: ":calendar:",
    src: "images/emoticons/emojis/calendar.png",
    css: "small",
    title: "calendar"
  },
  {key: ":date:", src: "images/emoticons/emojis/date.png", css: "small", title: "date"},
  {
    key: ":card_index:",
    src: "images/emoticons/emojis/card_index.png",
    css: "small",
    title: "card_index"
  },
  {
    key: ":file_folder:",
    src: "images/emoticons/emojis/file_folder.png",
    css: "small",
    title: "file_folder"
  },
  {
    key: ":open_file_folder:",
    src: "images/emoticons/emojis/open_file_folder.png",
    css: "small",
    title: "open_file_folder"
  },
  {
    key: ":scissors:",
    src: "images/emoticons/emojis/scissors.png",
    css: "small",
    title: "scissors"
  },
  {key: ":pushpin:", src: "images/emoticons/emojis/pushpin.png", css: "small", title: "pushpin"},
  {
    key: ":paperclip:",
    src: "images/emoticons/emojis/paperclip.png",
    css: "small",
    title: "paperclip"
  },
  {
    key: ":black_nib:",
    src: "images/emoticons/emojis/black_nib.png",
    css: "small",
    title: "black_nib"
  },
  {key: ":pencil2:", src: "images/emoticons/emojis/pencil2.png", css: "small", title: "pencil2"},
  {
    key: ":straight_ruler:",
    src: "images/emoticons/emojis/straight_ruler.png",
    css: "small",
    title: "straight_ruler"
  },
  {
    key: ":triangular_ruler:",
    src: "images/emoticons/emojis/triangular_ruler.png",
    css: "small",
    title: "triangular_ruler"
  },
  {
    key: ":closed_book:",
    src: "images/emoticons/emojis/closed_book.png",
    css: "small",
    title: "closed_book"
  },
  {
    key: ":green_book:",
    src: "images/emoticons/emojis/green_book.png",
    css: "small",
    title: "green_book"
  },
  {
    key: ":blue_book:",
    src: "images/emoticons/emojis/blue_book.png",
    css: "small",
    title: "blue_book"
  },
  {
    key: ":orange_book:",
    src: "images/emoticons/emojis/orange_book.png",
    css: "small",
    title: "orange_book"
  },
  {
    key: ":notebook:",
    src: "images/emoticons/emojis/notebook.png",
    css: "small",
    title: "notebook"
  },
  {
    key: ":notebook_with_decorative_cover:",
    src: "images/emoticons/emojis/notebook_with_decorative_cover.png",
    css: "small",
    title: "notebook_with_decorative_cover"
  },
  {key: ":ledger:", src: "images/emoticons/emojis/ledger.png", css: "small", title: "ledger"},
  {key: ":books:", src: "images/emoticons/emojis/books.png", css: "small", title: "books"},
  {
    key: ":bookmark:",
    src: "images/emoticons/emojis/bookmark.png",
    css: "small",
    title: "bookmark"
  },
  {
    key: ":name_badge:",
    src: "images/emoticons/emojis/name_badge.png",
    css: "small",
    title: "name_badge"
  },
  {
    key: ":microscope:",
    src: "images/emoticons/emojis/microscope.png",
    css: "small",
    title: "microscope"
  },
  {
    key: ":telescope:",
    src: "images/emoticons/emojis/telescope.png",
    css: "small",
    title: "telescope"
  },
  {
    key: ":newspaper:",
    src: "images/emoticons/emojis/newspaper.png",
    css: "small",
    title: "newspaper"
  },
  {
    key: ":football:",
    src: "images/emoticons/emojis/football.png",
    css: "small",
    title: "football"
  },
  {
    key: ":basketball:",
    src: "images/emoticons/emojis/basketball.png",
    css: "small",
    title: "basketball"
  },
  {key: ":soccer:", src: "images/emoticons/emojis/soccer.png", css: "small", title: "soccer"},
  {
    key: ":baseball:",
    src: "images/emoticons/emojis/baseball.png",
    css: "small",
    title: "baseball"
  },
  {key: ":tennis:", src: "images/emoticons/emojis/tennis.png", css: "small", title: "tennis"},
  {key: ":8ball:", src: "images/emoticons/emojis/8ball.png", css: "small", title: "8ball"},
  {
    key: ":rugby_football:",
    src: "images/emoticons/emojis/rugby_football.png",
    css: "small",
    title: "rugby_football"
  },
  {key: ":bowling:", src: "images/emoticons/emojis/bowling.png", css: "small", title: "bowling"},
  {key: ":golf:", src: "images/emoticons/emojis/golf.png", css: "small", title: "golf"},
  {
    key: ":mountain_bicyclist:",
    src: "images/emoticons/emojis/mountain_bicyclist.png",
    css: "small",
    title: "mountain_bicyclist"
  },
  {
    key: ":bicyclist:",
    src: "images/emoticons/emojis/bicyclist.png",
    css: "small",
    title: "bicyclist"
  },
  {
    key: ":horse_racing:",
    src: "images/emoticons/emojis/horse_racing.png",
    css: "small",
    title: "horse_racing"
  },
  {
    key: ":snowboarder:",
    src: "images/emoticons/emojis/snowboarder.png",
    css: "small",
    title: "snowboarder"
  },
  {key: ":swimmer:", src: "images/emoticons/emojis/swimmer.png", css: "small", title: "swimmer"},
  {key: ":surfer:", src: "images/emoticons/emojis/surfer.png", css: "small", title: "surfer"},
  {key: ":ski:", src: "images/emoticons/emojis/ski.png", css: "small", title: "ski"},
  {key: ":spades:", src: "images/emoticons/emojis/spades.png", css: "small", title: "spades"},
  {key: ":hearts:", src: "images/emoticons/emojis/hearts.png", css: "small", title: "hearts"},
  {key: ":clubs:", src: "images/emoticons/emojis/clubs.png", css: "small", title: "clubs"},
  {
    key: ":diamonds:",
    src: "images/emoticons/emojis/diamonds.png",
    css: "small",
    title: "diamonds"
  },
  {key: ":gem:", src: "images/emoticons/emojis/gem.png", css: "small", title: "gem"},
  {key: ":ring:", src: "images/emoticons/emojis/ring.png", css: "small", title: "ring"},
  {key: ":trophy:", src: "images/emoticons/emojis/trophy.png", css: "small", title: "trophy"},
  {
    key: ":musical_score:",
    src: "images/emoticons/emojis/musical_score.png",
    css: "small",
    title: "musical_score"
  },
  {
    key: ":musical_keyboard:",
    src: "images/emoticons/emojis/musical_keyboard.png",
    css: "small",
    title: "musical_keyboard"
  },
  {key: ":violin:", src: "images/emoticons/emojis/violin.png", css: "small", title: "violin"},
  {
    key: ":space_invader:",
    src: "images/emoticons/emojis/space_invader.png",
    css: "small",
    title: "space_invader"
  },
  {
    key: ":video_game:",
    src: "images/emoticons/emojis/video_game.png",
    css: "small",
    title: "video_game"
  },
  {
    key: ":black_joker:",
    src: "images/emoticons/emojis/black_joker.png",
    css: "small",
    title: "black_joker"
  },
  {
    key: ":flower_playing_cards:",
    src: "images/emoticons/emojis/flower_playing_cards.png",
    css: "small",
    title: "flower_playing_cards"
  },
  {
    key: ":game_die:",
    src: "images/emoticons/emojis/game_die.png",
    css: "small",
    title: "game_die"
  },
  {key: ":dart:", src: "images/emoticons/emojis/dart.png", css: "small", title: "dart"},
  {key: ":mahjong:", src: "images/emoticons/emojis/mahjong.png", css: "small", title: "mahjong"},
  {key: ":clapper:", src: "images/emoticons/emojis/clapper.png", css: "small", title: "clapper"},
  {key: ":memo:", src: "images/emoticons/emojis/memo.png", css: "small", title: "memo"},
  {key: ":pencil:", src: "images/emoticons/emojis/pencil.png", css: "small", title: "pencil"},
  {key: ":book:", src: "images/emoticons/emojis/book.png", css: "small", title: "book"},
  {key: ":art:", src: "images/emoticons/emojis/art.png", css: "small", title: "art"},
  {
    key: ":microphone:",
    src: "images/emoticons/emojis/microphone.png",
    css: "small",
    title: "microphone"
  },
  {
    key: ":headphones:",
    src: "images/emoticons/emojis/headphones.png",
    css: "small",
    title: "headphones"
  },
  {key: ":trumpet:", src: "images/emoticons/emojis/trumpet.png", css: "small", title: "trumpet"},
  {
    key: ":saxophone:",
    src: "images/emoticons/emojis/saxophone.png",
    css: "small",
    title: "saxophone"
  },
  {key: ":guitar:", src: "images/emoticons/emojis/guitar.png", css: "small", title: "guitar"},
  {key: ":shoe:", src: "images/emoticons/emojis/shoe.png", css: "small", title: "shoe"},
  {key: ":sandal:", src: "images/emoticons/emojis/sandal.png", css: "small", title: "sandal"},
  {
    key: ":high_heel:",
    src: "images/emoticons/emojis/high_heel.png",
    css: "small",
    title: "high_heel"
  },
  {
    key: ":lipstick:",
    src: "images/emoticons/emojis/lipstick.png",
    css: "small",
    title: "lipstick"
  },
  {key: ":boot:", src: "images/emoticons/emojis/boot.png", css: "small", title: "boot"},
  {key: ":shirt:", src: "images/emoticons/emojis/shirt.png", css: "small", title: "shirt"},
  {key: ":tshirt:", src: "images/emoticons/emojis/tshirt.png", css: "small", title: "tshirt"},
  {key: ":necktie:", src: "images/emoticons/emojis/necktie.png", css: "small", title: "necktie"},
  {
    key: ":womans_clothes:",
    src: "images/emoticons/emojis/womans_clothes.png",
    css: "small",
    title: "womans_clothes"
  },
  {key: ":dress:", src: "images/emoticons/emojis/dress.png", css: "small", title: "dress"},
  {
    key: ":running_shirt_with_sash:",
    src: "images/emoticons/emojis/running_shirt_with_sash.png",
    css: "small",
    title: "running_shirt_with_sash"
  },
  {key: ":jeans:", src: "images/emoticons/emojis/jeans.png", css: "small", title: "jeans"},
  {key: ":kimono:", src: "images/emoticons/emojis/kimono.png", css: "small", title: "kimono"},
  {key: ":bikini:", src: "images/emoticons/emojis/bikini.png", css: "small", title: "bikini"},
  {key: ":ribbon:", src: "images/emoticons/emojis/ribbon.png", css: "small", title: "ribbon"},
  {key: ":tophat:", src: "images/emoticons/emojis/tophat.png", css: "small", title: "tophat"},
  {key: ":crown:", src: "images/emoticons/emojis/crown.png", css: "small", title: "crown"},
  {
    key: ":womans_hat:",
    src: "images/emoticons/emojis/womans_hat.png",
    css: "small",
    title: "womans_hat"
  },
  {
    key: ":mans_shoe:",
    src: "images/emoticons/emojis/mans_shoe.png",
    css: "small",
    title: "mans_shoe"
  },
  {
    key: ":closed_umbrella:",
    src: "images/emoticons/emojis/closed_umbrella.png",
    css: "small",
    title: "closed_umbrella"
  },
  {
    key: ":briefcase:",
    src: "images/emoticons/emojis/briefcase.png",
    css: "small",
    title: "briefcase"
  },
  {key: ":handbag:", src: "images/emoticons/emojis/handbag.png", css: "small", title: "handbag"},
  {key: ":pouch:", src: "images/emoticons/emojis/pouch.png", css: "small", title: "pouch"},
  {key: ":purse:", src: "images/emoticons/emojis/purse.png", css: "small", title: "purse"},
  {
    key: ":eyeglasses:",
    src: "images/emoticons/emojis/eyeglasses.png",
    css: "small",
    title: "eyeglasses"
  },
  {
    key: ":fishing_pole_and_fish:",
    src: "images/emoticons/emojis/fishing_pole_and_fish.png",
    css: "small",
    title: "fishing_pole_and_fish"
  },
  {key: ":coffee:", src: "images/emoticons/emojis/coffee.png", css: "small", title: "coffee"},
  {key: ":tea:", src: "images/emoticons/emojis/tea.png", css: "small", title: "tea"},
  {key: ":sake:", src: "images/emoticons/emojis/sake.png", css: "small", title: "sake"},
  {
    key: ":baby_bottle:",
    src: "images/emoticons/emojis/baby_bottle.png",
    css: "small",
    title: "baby_bottle"
  },
  {key: ":beer:", src: "images/emoticons/emojis/beer.png", css: "small", title: "beer"},
  {key: ":beers:", src: "images/emoticons/emojis/beers.png", css: "small", title: "beers"},
  {
    key: ":cocktail:",
    src: "images/emoticons/emojis/cocktail.png",
    css: "small",
    title: "cocktail"
  },
  {
    key: ":tropical_drink:",
    src: "images/emoticons/emojis/tropical_drink.png",
    css: "small",
    title: "tropical_drink"
  },
  {
    key: ":wine_glass:",
    src: "images/emoticons/emojis/wine_glass.png",
    css: "small",
    title: "wine_glass"
  },
  {
    key: ":fork_and_knife:",
    src: "images/emoticons/emojis/fork_and_knife.png",
    css: "small",
    title: "fork_and_knife"
  },
  {key: ":pizza:", src: "images/emoticons/emojis/pizza.png", css: "small", title: "pizza"},
  {
    key: ":hamburger:",
    src: "images/emoticons/emojis/hamburger.png",
    css: "small",
    title: "hamburger"
  },
  {key: ":fries:", src: "images/emoticons/emojis/fries.png", css: "small", title: "fries"},
  {
    key: ":poultry_leg:",
    src: "images/emoticons/emojis/poultry_leg.png",
    css: "small",
    title: "poultry_leg"
  },
  {
    key: ":meat_on_bone:",
    src: "images/emoticons/emojis/meat_on_bone.png",
    css: "small",
    title: "meat_on_bone"
  },
  {
    key: ":spaghetti:",
    src: "images/emoticons/emojis/spaghetti.png",
    css: "small",
    title: "spaghetti"
  },
  {key: ":curry:", src: "images/emoticons/emojis/curry.png", css: "small", title: "curry"},
  {
    key: ":fried_shrimp:",
    src: "images/emoticons/emojis/fried_shrimp.png",
    css: "small",
    title: "fried_shrimp"
  },
  {key: ":bento:", src: "images/emoticons/emojis/bento.png", css: "small", title: "bento"},
  {key: ":sushi:", src: "images/emoticons/emojis/sushi.png", css: "small", title: "sushi"},
  {
    key: ":fish_cake:",
    src: "images/emoticons/emojis/fish_cake.png",
    css: "small",
    title: "fish_cake"
  },
  {
    key: ":rice_ball:",
    src: "images/emoticons/emojis/rice_ball.png",
    css: "small",
    title: "rice_ball"
  },
  {
    key: ":rice_cracker:",
    src: "images/emoticons/emojis/rice_cracker.png",
    css: "small",
    title: "rice_cracker"
  },
  {key: ":rice:", src: "images/emoticons/emojis/rice.png", css: "small", title: "rice"},
  {key: ":ramen:", src: "images/emoticons/emojis/ramen.png", css: "small", title: "ramen"},
  {key: ":stew:", src: "images/emoticons/emojis/stew.png", css: "small", title: "stew"},
  {key: ":oden:", src: "images/emoticons/emojis/oden.png", css: "small", title: "oden"},
  {key: ":dango:", src: "images/emoticons/emojis/dango.png", css: "small", title: "dango"},
  {key: ":egg:", src: "images/emoticons/emojis/egg.png", css: "small", title: "egg"},
  {key: ":bread:", src: "images/emoticons/emojis/bread.png", css: "small", title: "bread"},
  {
    key: ":doughnut:",
    src: "images/emoticons/emojis/doughnut.png",
    css: "small",
    title: "doughnut"
  },
  {key: ":custard:", src: "images/emoticons/emojis/custard.png", css: "small", title: "custard"},
  {
    key: ":icecream:",
    src: "images/emoticons/emojis/icecream.png",
    css: "small",
    title: "icecream"
  },
  {
    key: ":ice_cream:",
    src: "images/emoticons/emojis/ice_cream.png",
    css: "small",
    title: "ice_cream"
  },
  {
    key: ":shaved_ice:",
    src: "images/emoticons/emojis/shaved_ice.png",
    css: "small",
    title: "shaved_ice"
  },
  {
    key: ":birthday:",
    src: "images/emoticons/emojis/birthday.png",
    css: "small",
    title: "birthday"
  },
  {key: ":cake:", src: "images/emoticons/emojis/cake.png", css: "small", title: "cake"},
  {key: ":cookie:", src: "images/emoticons/emojis/cookie.png", css: "small", title: "cookie"},
  {
    key: ":chocolate_bar:",
    src: "images/emoticons/emojis/chocolate_bar.png",
    css: "small",
    title: "chocolate_bar"
  },
  {key: ":candy:", src: "images/emoticons/emojis/candy.png", css: "small", title: "candy"},
  {
    key: ":lollipop:",
    src: "images/emoticons/emojis/lollipop.png",
    css: "small",
    title: "lollipop"
  },
  {
    key: ":honey_pot:",
    src: "images/emoticons/emojis/honey_pot.png",
    css: "small",
    title: "honey_pot"
  },
  {key: ":apple:", src: "images/emoticons/emojis/apple.png", css: "small", title: "apple"},
  {
    key: ":green_apple:",
    src: "images/emoticons/emojis/green_apple.png",
    css: "small",
    title: "green_apple"
  },
  {
    key: ":tangerine:",
    src: "images/emoticons/emojis/tangerine.png",
    css: "small",
    title: "tangerine"
  },
  {key: ":lemon:", src: "images/emoticons/emojis/lemon.png", css: "small", title: "lemon"},
  {
    key: ":cherries:",
    src: "images/emoticons/emojis/cherries.png",
    css: "small",
    title: "cherries"
  },
  {key: ":grapes:", src: "images/emoticons/emojis/grapes.png", css: "small", title: "grapes"},
  {
    key: ":watermelon:",
    src: "images/emoticons/emojis/watermelon.png",
    css: "small",
    title: "watermelon"
  },
  {
    key: ":strawberry:",
    src: "images/emoticons/emojis/strawberry.png",
    css: "small",
    title: "strawberry"
  },
  {key: ":peach:", src: "images/emoticons/emojis/peach.png", css: "small", title: "peach"},
  {key: ":melon:", src: "images/emoticons/emojis/melon.png", css: "small", title: "melon"},
  {key: ":banana:", src: "images/emoticons/emojis/banana.png", css: "small", title: "banana"},
  {key: ":pear:", src: "images/emoticons/emojis/pear.png", css: "small", title: "pear"},
  {
    key: ":pineapple:",
    src: "images/emoticons/emojis/pineapple.png",
    css: "small",
    title: "pineapple"
  },
  {
    key: ":sweet_potato:",
    src: "images/emoticons/emojis/sweet_potato.png",
    css: "small",
    title: "sweet_potato"
  },
  {
    key: ":eggplant:",
    src: "images/emoticons/emojis/eggplant.png",
    css: "small",
    title: "eggplant"
  },
  {key: ":tomato:", src: "images/emoticons/emojis/tomato.png", css: "small", title: "tomato"},
  {key: ":corn:", src: "images/emoticons/emojis/corn.png", css: "small", title: "corn"},
  {key: ":house:", src: "images/emoticons/emojis/house.png", css: "small", title: "house"},
  {
    key: ":house_with_garden:",
    src: "images/emoticons/emojis/house_with_garden.png",
    css: "small",
    title: "house_with_garden"
  },
  {key: ":school:", src: "images/emoticons/emojis/school.png", css: "small", title: "school"},
  {key: ":office:", src: "images/emoticons/emojis/office.png", css: "small", title: "office"},
  {
    key: ":post_office:",
    src: "images/emoticons/emojis/post_office.png",
    css: "small",
    title: "post_office"
  },
  {
    key: ":hospital:",
    src: "images/emoticons/emojis/hospital.png",
    css: "small",
    title: "hospital"
  },
  {key: ":bank:", src: "images/emoticons/emojis/bank.png", css: "small", title: "bank"},
  {
    key: ":convenience_store:",
    src: "images/emoticons/emojis/convenience_store.png",
    css: "small",
    title: "convenience_store"
  },
  {
    key: ":love_hotel:",
    src: "images/emoticons/emojis/love_hotel.png",
    css: "small",
    title: "love_hotel"
  },
  {key: ":hotel:", src: "images/emoticons/emojis/hotel.png", css: "small", title: "hotel"},
  {key: ":wedding:", src: "images/emoticons/emojis/wedding.png", css: "small", title: "wedding"},
  {key: ":church:", src: "images/emoticons/emojis/church.png", css: "small", title: "church"},
  {
    key: ":department_store:",
    src: "images/emoticons/emojis/department_store.png",
    css: "small",
    title: "department_store"
  },
  {
    key: ":european_post_office:",
    src: "images/emoticons/emojis/european_post_office.png",
    css: "small",
    title: "european_post_office"
  },
  {
    key: ":city_sunrise:",
    src: "images/emoticons/emojis/city_sunrise.png",
    css: "small",
    title: "city_sunrise"
  },
  {
    key: ":city_sunset:",
    src: "images/emoticons/emojis/city_sunset.png",
    css: "small",
    title: "city_sunset"
  },
  {
    key: ":japanese_castle:",
    src: "images/emoticons/emojis/japanese_castle.png",
    css: "small",
    title: "japanese_castle"
  },
  {
    key: ":european_castle:",
    src: "images/emoticons/emojis/european_castle.png",
    css: "small",
    title: "european_castle"
  },
  {key: ":tent:", src: "images/emoticons/emojis/tent.png", css: "small", title: "tent"},
  {key: ":factory:", src: "images/emoticons/emojis/factory.png", css: "small", title: "factory"},
  {
    key: ":tokyo_tower:",
    src: "images/emoticons/emojis/tokyo_tower.png",
    css: "small",
    title: "tokyo_tower"
  },
  {key: ":japan:", src: "images/emoticons/emojis/japan.png", css: "small", title: "japan"},
  {
    key: ":mount_fuji:",
    src: "images/emoticons/emojis/mount_fuji.png",
    css: "small",
    title: "mount_fuji"
  },
  {
    key: ":sunrise_over_mountains:",
    src: "images/emoticons/emojis/sunrise_over_mountains.png",
    css: "small",
    title: "sunrise_over_mountains"
  },
  {key: ":sunrise:", src: "images/emoticons/emojis/sunrise.png", css: "small", title: "sunrise"},
  {key: ":stars:", src: "images/emoticons/emojis/stars.png", css: "small", title: "stars"},
  {
    key: ":statue_of_liberty:",
    src: "images/emoticons/emojis/statue_of_liberty.png",
    css: "small",
    title: "statue_of_liberty"
  },
  {
    key: ":bridge_at_night:",
    src: "images/emoticons/emojis/bridge_at_night.png",
    css: "small",
    title: "bridge_at_night"
  },
  {
    key: ":carousel_horse:",
    src: "images/emoticons/emojis/carousel_horse.png",
    css: "small",
    title: "carousel_horse"
  },
  {key: ":rainbow:", src: "images/emoticons/emojis/rainbow.png", css: "small", title: "rainbow"},
  {
    key: ":ferris_wheel:",
    src: "images/emoticons/emojis/ferris_wheel.png",
    css: "small",
    title: "ferris_wheel"
  },
  {
    key: ":fountain:",
    src: "images/emoticons/emojis/fountain.png",
    css: "small",
    title: "fountain"
  },
  {
    key: ":roller_coaster:",
    src: "images/emoticons/emojis/roller_coaster.png",
    css: "small",
    title: "roller_coaster"
  },
  {key: ":ship:", src: "images/emoticons/emojis/ship.png", css: "small", title: "ship"},
  {
    key: ":speedboat:",
    src: "images/emoticons/emojis/speedboat.png",
    css: "small",
    title: "speedboat"
  },
  {key: ":boat:", src: "images/emoticons/emojis/boat.png", css: "small", title: "boat"},
  {
    key: ":sailboat:",
    src: "images/emoticons/emojis/sailboat.png",
    css: "small",
    title: "sailboat"
  },
  {key: ":rowboat:", src: "images/emoticons/emojis/rowboat.png", css: "small", title: "rowboat"},
  {key: ":anchor:", src: "images/emoticons/emojis/anchor.png", css: "small", title: "anchor"},
  {key: ":rocket:", src: "images/emoticons/emojis/rocket.png", css: "small", title: "rocket"},
  {
    key: ":airplane:",
    src: "images/emoticons/emojis/airplane.png",
    css: "small",
    title: "airplane"
  },
  {
    key: ":helicopter:",
    src: "images/emoticons/emojis/helicopter.png",
    css: "small",
    title: "helicopter"
  },
  {
    key: ":steam_locomotive:",
    src: "images/emoticons/emojis/steam_locomotive.png",
    css: "small",
    title: "steam_locomotive"
  },
  {key: ":tram:", src: "images/emoticons/emojis/tram.png", css: "small", title: "tram"},
  {
    key: ":mountain_railway:",
    src: "images/emoticons/emojis/mountain_railway.png",
    css: "small",
    title: "mountain_railway"
  },
  {key: ":bike:", src: "images/emoticons/emojis/bike.png", css: "small", title: "bike"},
  {
    key: ":aerial_tramway:",
    src: "images/emoticons/emojis/aerial_tramway.png",
    css: "small",
    title: "aerial_tramway"
  },
  {
    key: ":suspension_railway:",
    src: "images/emoticons/emojis/suspension_railway.png",
    css: "small",
    title: "suspension_railway"
  },
  {
    key: ":mountain_cableway:",
    src: "images/emoticons/emojis/mountain_cableway.png",
    css: "small",
    title: "mountain_cableway"
  },
  {key: ":tractor:", src: "images/emoticons/emojis/tractor.png", css: "small", title: "tractor"},
  {
    key: ":blue_car:",
    src: "images/emoticons/emojis/blue_car.png",
    css: "small",
    title: "blue_car"
  },
  {
    key: ":oncoming_automobile:",
    src: "images/emoticons/emojis/oncoming_automobile.png",
    css: "small",
    title: "oncoming_automobile"
  },
  {key: ":car:", src: "images/emoticons/emojis/car.png", css: "small", title: "car"},
  {key: ":red_car:", src: "images/emoticons/emojis/red_car.png", css: "small", title: "red_car"},
  {key: ":taxi:", src: "images/emoticons/emojis/taxi.png", css: "small", title: "taxi"},
  {
    key: ":oncoming_taxi:",
    src: "images/emoticons/emojis/oncoming_taxi.png",
    css: "small",
    title: "oncoming_taxi"
  },
  {
    key: ":articulated_lorry:",
    src: "images/emoticons/emojis/articulated_lorry.png",
    css: "small",
    title: "articulated_lorry"
  },
  {key: ":bus:", src: "images/emoticons/emojis/bus.png", css: "small", title: "bus"},
  {
    key: ":oncoming_bus:",
    src: "images/emoticons/emojis/oncoming_bus.png",
    css: "small",
    title: "oncoming_bus"
  },
  {
    key: ":rotating_light:",
    src: "images/emoticons/emojis/rotating_light.png",
    css: "small",
    title: "rotating_light"
  },
  {
    key: ":police_car:",
    src: "images/emoticons/emojis/police_car.png",
    css: "small",
    title: "police_car"
  },
  {
    key: ":oncoming_police_car:",
    src: "images/emoticons/emojis/oncoming_police_car.png",
    css: "small",
    title: "oncoming_police_car"
  },
  {
    key: ":fire_engine:",
    src: "images/emoticons/emojis/fire_engine.png",
    css: "small",
    title: "fire_engine"
  },
  {
    key: ":ambulance:",
    src: "images/emoticons/emojis/ambulance.png",
    css: "small",
    title: "ambulance"
  },
  {key: ":minibus:", src: "images/emoticons/emojis/minibus.png", css: "small", title: "minibus"},
  {key: ":truck:", src: "images/emoticons/emojis/truck.png", css: "small", title: "truck"},
  {key: ":train:", src: "images/emoticons/emojis/train.png", css: "small", title: "train"},
  {key: ":station:", src: "images/emoticons/emojis/station.png", css: "small", title: "station"},
  {key: ":train2:", src: "images/emoticons/emojis/train2.png", css: "small", title: "train2"},
  {
    key: ":bullettrain_front:",
    src: "images/emoticons/emojis/bullettrain_front.png",
    css: "small",
    title: "bullettrain_front"
  },
  {
    key: ":bullettrain_side:",
    src: "images/emoticons/emojis/bullettrain_side.png",
    css: "small",
    title: "bullettrain_side"
  },
  {
    key: ":light_rail:",
    src: "images/emoticons/emojis/light_rail.png",
    css: "small",
    title: "light_rail"
  },
  {
    key: ":monorail:",
    src: "images/emoticons/emojis/monorail.png",
    css: "small",
    title: "monorail"
  },
  {
    key: ":railway_car:",
    src: "images/emoticons/emojis/railway_car.png",
    css: "small",
    title: "railway_car"
  },
  {
    key: ":trolleybus:",
    src: "images/emoticons/emojis/trolleybus.png",
    css: "small",
    title: "trolleybus"
  },
  {key: ":ticket:", src: "images/emoticons/emojis/ticket.png", css: "small", title: "ticket"},
  {
    key: ":fuelpump:",
    src: "images/emoticons/emojis/fuelpump.png",
    css: "small",
    title: "fuelpump"
  },
  {
    key: ":vertical_traffic_light:",
    src: "images/emoticons/emojis/vertical_traffic_light.png",
    css: "small",
    title: "vertical_traffic_light"
  },
  {
    key: ":traffic_light:",
    src: "images/emoticons/emojis/traffic_light.png",
    css: "small",
    title: "traffic_light"
  },
  {key: ":warning:", src: "images/emoticons/emojis/warning.png", css: "small", title: "warning"},
  {
    key: ":construction:",
    src: "images/emoticons/emojis/construction.png",
    css: "small",
    title: "construction"
  },
  {
    key: ":beginner:",
    src: "images/emoticons/emojis/beginner.png",
    css: "small",
    title: "beginner"
  },
  {key: ":atm:", src: "images/emoticons/emojis/atm.png", css: "small", title: "atm"},
  {
    key: ":slot_machine:",
    src: "images/emoticons/emojis/slot_machine.png",
    css: "small",
    title: "slot_machine"
  },
  {key: ":busstop:", src: "images/emoticons/emojis/busstop.png", css: "small", title: "busstop"},
  {key: ":barber:", src: "images/emoticons/emojis/barber.png", css: "small", title: "barber"},
  {
    key: ":hotsprings:",
    src: "images/emoticons/emojis/hotsprings.png",
    css: "small",
    title: "hotsprings"
  },
  {
    key: ":checkered_flag:",
    src: "images/emoticons/emojis/checkered_flag.png",
    css: "small",
    title: "checkered_flag"
  },
  {
    key: ":crossed_flags:",
    src: "images/emoticons/emojis/crossed_flags.png",
    css: "small",
    title: "crossed_flags"
  },
  {
    key: ":izakaya_lantern:",
    src: "images/emoticons/emojis/izakaya_lantern.png",
    css: "small",
    title: "izakaya_lantern"
  },
  {key: ":moyai:", src: "images/emoticons/emojis/moyai.png", css: "small", title: "moyai"},
  {
    key: ":circus_tent:",
    src: "images/emoticons/emojis/circus_tent.png",
    css: "small",
    title: "circus_tent"
  },
  {
    key: ":performing_arts:",
    src: "images/emoticons/emojis/performing_arts.png",
    css: "small",
    title: "performing_arts"
  },
  {
    key: ":round_pushpin:",
    src: "images/emoticons/emojis/round_pushpin.png",
    css: "small",
    title: "round_pushpin"
  },
  {
    key: ":triangular_flag_on_post:",
    src: "images/emoticons/emojis/triangular_flag_on_post.png",
    css: "small",
    title: "triangular_flag_on_post"
  },
  {key: ":jp:", src: "images/emoticons/emojis/jp.png", css: "small", title: "jp"},
  {key: ":kr:", src: "images/emoticons/emojis/kr.png", css: "small", title: "kr"},
  {key: ":cn:", src: "images/emoticons/emojis/cn.png", css: "small", title: "cn"},
  {key: ":us:", src: "images/emoticons/emojis/us.png", css: "small", title: "us"},
  {key: ":fr:", src: "images/emoticons/emojis/fr.png", css: "small", title: "fr"},
  {key: ":es:", src: "images/emoticons/emojis/es.png", css: "small", title: "es"},
  {key: ":it:", src: "images/emoticons/emojis/it.png", css: "small", title: "it"},
  {key: ":ru:", src: "images/emoticons/emojis/ru.png", css: "small", title: "ru"},
  {key: ":gb:", src: "images/emoticons/emojis/gb.png", css: "small", title: "gb"},
  {key: ":uk:", src: "images/emoticons/emojis/uk.png", css: "small", title: "uk"},
  {key: ":de:", src: "images/emoticons/emojis/de.png", css: "small", title: "de"},
  {key: ":one:", src: "images/emoticons/emojis/one.png", css: "small", title: "one"},
  {key: ":two:", src: "images/emoticons/emojis/two.png", css: "small", title: "two"},
  {key: ":three:", src: "images/emoticons/emojis/three.png", css: "small", title: "three"},
  {key: ":four:", src: "images/emoticons/emojis/four.png", css: "small", title: "four"},
  {key: ":five:", src: "images/emoticons/emojis/five.png", css: "small", title: "five"},
  {key: ":six:", src: "images/emoticons/emojis/six.png", css: "small", title: "six"},
  {key: ":seven:", src: "images/emoticons/emojis/seven.png", css: "small", title: "seven"},
  {key: ":eight:", src: "images/emoticons/emojis/eight.png", css: "small", title: "eight"},
  {key: ":nine:", src: "images/emoticons/emojis/nine.png", css: "small", title: "nine"},
  {
    key: ":keycap_ten:",
    src: "images/emoticons/emojis/keycap_ten.png",
    css: "small",
    title: "keycap_ten"
  },
  {key: ":1234:", src: "images/emoticons/emojis/1234.png", css: "small", title: "1234"},
  {key: ":zero:", src: "images/emoticons/emojis/zero.png", css: "small", title: "zero"},
  {key: ":hash:", src: "images/emoticons/emojis/hash.png", css: "small", title: "hash"},
  {key: ":symbols:", src: "images/emoticons/emojis/symbols.png", css: "small", title: "symbols"},
  {
    key: ":arrow_backward:",
    src: "images/emoticons/emojis/arrow_backward.png",
    css: "small",
    title: "arrow_backward"
  },
  {
    key: ":arrow_down:",
    src: "images/emoticons/emojis/arrow_down.png",
    css: "small",
    title: "arrow_down"
  },
  {
    key: ":arrow_forward:",
    src: "images/emoticons/emojis/arrow_forward.png",
    css: "small",
    title: "arrow_forward"
  },
  {
    key: ":arrow_left:",
    src: "images/emoticons/emojis/arrow_left.png",
    css: "small",
    title: "arrow_left"
  },
  {
    key: ":capital_abcd:",
    src: "images/emoticons/emojis/capital_abcd.png",
    css: "small",
    title: "capital_abcd"
  },
  {key: ":abcd:", src: "images/emoticons/emojis/abcd.png", css: "small", title: "abcd"},
  {key: ":abc:", src: "images/emoticons/emojis/abc.png", css: "small", title: "abc"},
  {
    key: ":arrow_lower_left:",
    src: "images/emoticons/emojis/arrow_lower_left.png",
    css: "small",
    title: "arrow_lower_left"
  },
  {
    key: ":arrow_lower_right:",
    src: "images/emoticons/emojis/arrow_lower_right.png",
    css: "small",
    title: "arrow_lower_right"
  },
  {
    key: ":arrow_right:",
    src: "images/emoticons/emojis/arrow_right.png",
    css: "small",
    title: "arrow_right"
  },
  {
    key: ":arrow_up:",
    src: "images/emoticons/emojis/arrow_up.png",
    css: "small",
    title: "arrow_up"
  },
  {
    key: ":arrow_upper_left:",
    src: "images/emoticons/emojis/arrow_upper_left.png",
    css: "small",
    title: "arrow_upper_left"
  },
  {
    key: ":arrow_upper_right:",
    src: "images/emoticons/emojis/arrow_upper_right.png",
    css: "small",
    title: "arrow_upper_right"
  },
  {
    key: ":arrow_double_down:",
    src: "images/emoticons/emojis/arrow_double_down.png",
    css: "small",
    title: "arrow_double_down"
  },
  {
    key: ":arrow_double_up:",
    src: "images/emoticons/emojis/arrow_double_up.png",
    css: "small",
    title: "arrow_double_up"
  },
  {
    key: ":arrow_down_small:",
    src: "images/emoticons/emojis/arrow_down_small.png",
    css: "small",
    title: "arrow_down_small"
  },
  {
    key: ":arrow_heading_down:",
    src: "images/emoticons/emojis/arrow_heading_down.png",
    css: "small",
    title: "arrow_heading_down"
  },
  {
    key: ":arrow_heading_up:",
    src: "images/emoticons/emojis/arrow_heading_up.png",
    css: "small",
    title: "arrow_heading_up"
  },
  {
    key: ":leftwards_arrow_with_hook:",
    src: "images/emoticons/emojis/leftwards_arrow_with_hook.png",
    css: "small",
    title: "leftwards_arrow_with_hook"
  },
  {
    key: ":arrow_right_hook:",
    src: "images/emoticons/emojis/arrow_right_hook.png",
    css: "small",
    title: "arrow_right_hook"
  },
  {
    key: ":left_right_arrow:",
    src: "images/emoticons/emojis/left_right_arrow.png",
    css: "small",
    title: "left_right_arrow"
  },
  {
    key: ":arrow_up_down:",
    src: "images/emoticons/emojis/arrow_up_down.png",
    css: "small",
    title: "arrow_up_down"
  },
  {
    key: ":arrow_up_small:",
    src: "images/emoticons/emojis/arrow_up_small.png",
    css: "small",
    title: "arrow_up_small"
  },
  {
    key: ":arrows_clockwise:",
    src: "images/emoticons/emojis/arrows_clockwise.png",
    css: "small",
    title: "arrows_clockwise"
  },
  {
    key: ":arrows_counterclockwise:",
    src: "images/emoticons/emojis/arrows_counterclockwise.png",
    css: "small",
    title: "arrows_counterclockwise"
  },
  {key: ":rewind:", src: "images/emoticons/emojis/rewind.png", css: "small", title: "rewind"},
  {
    key: ":fast_forward:",
    src: "images/emoticons/emojis/fast_forward.png",
    css: "small",
    title: "fast_forward"
  },
  {
    key: ":information_source:",
    src: "images/emoticons/emojis/information_source.png",
    css: "small",
    title: "information_source"
  },
  {key: ":ok:", src: "images/emoticons/emojis/ok.png", css: "small", title: "ok"},
  {
    key: ":twisted_rightwards_arrows:",
    src: "images/emoticons/emojis/twisted_rightwards_arrows.png",
    css: "small",
    title: "twisted_rightwards_arrows"
  },
  {key: ":repeat:", src: "images/emoticons/emojis/repeat.png", css: "small", title: "repeat"},
  {
    key: ":repeat_one:",
    src: "images/emoticons/emojis/repeat_one.png",
    css: "small",
    title: "repeat_one"
  },
  {key: ":new:", src: "images/emoticons/emojis/new.png", css: "small", title: "new"},
  {key: ":top:", src: "images/emoticons/emojis/top.png", css: "small", title: "top"},
  {key: ":up:", src: "images/emoticons/emojis/up.png", css: "small", title: "up"},
  {key: ":cool:", src: "images/emoticons/emojis/cool.png", css: "small", title: "cool"},
  {key: ":free:", src: "images/emoticons/emojis/free.png", css: "small", title: "free"},
  {key: ":ng:", src: "images/emoticons/emojis/ng.png", css: "small", title: "ng"},
  {key: ":cinema:", src: "images/emoticons/emojis/cinema.png", css: "small", title: "cinema"},
  {key: ":koko:", src: "images/emoticons/emojis/koko.png", css: "small", title: "koko"},
  {
    key: ":signal_strength:",
    src: "images/emoticons/emojis/signal_strength.png",
    css: "small",
    title: "signal_strength"
  },
  {key: ":u5272:", src: "images/emoticons/emojis/u5272.png", css: "small", title: "u5272"},
  {key: ":u5408:", src: "images/emoticons/emojis/u5408.png", css: "small", title: "u5408"},
  {key: ":u55b6:", src: "images/emoticons/emojis/u55b6.png", css: "small", title: "u55b6"},
  {key: ":u6307:", src: "images/emoticons/emojis/u6307.png", css: "small", title: "u6307"},
  {key: ":u6708:", src: "images/emoticons/emojis/u6708.png", css: "small", title: "u6708"},
  {key: ":u6709:", src: "images/emoticons/emojis/u6709.png", css: "small", title: "u6709"},
  {key: ":u6e80:", src: "images/emoticons/emojis/u6e80.png", css: "small", title: "u6e80"},
  {key: ":u7121:", src: "images/emoticons/emojis/u7121.png", css: "small", title: "u7121"},
  {key: ":u7533:", src: "images/emoticons/emojis/u7533.png", css: "small", title: "u7533"},
  {key: ":u7a7a:", src: "images/emoticons/emojis/u7a7a.png", css: "small", title: "u7a7a"},
  {key: ":u7981:", src: "images/emoticons/emojis/u7981.png", css: "small", title: "u7981"},
  {key: ":sa:", src: "images/emoticons/emojis/sa.png", css: "small", title: "sa"},
  {
    key: ":restroom:",
    src: "images/emoticons/emojis/restroom.png",
    css: "small",
    title: "restroom"
  },
  {key: ":mens:", src: "images/emoticons/emojis/mens.png", css: "small", title: "mens"},
  {key: ":womens:", src: "images/emoticons/emojis/womens.png", css: "small", title: "womens"},
  {
    key: ":baby_symbol:",
    src: "images/emoticons/emojis/baby_symbol.png",
    css: "small",
    title: "baby_symbol"
  },
  {
    key: ":no_smoking:",
    src: "images/emoticons/emojis/no_smoking.png",
    css: "small",
    title: "no_smoking"
  },
  {key: ":parking:", src: "images/emoticons/emojis/parking.png", css: "small", title: "parking"},
  {
    key: ":wheelchair:",
    src: "images/emoticons/emojis/wheelchair.png",
    css: "small",
    title: "wheelchair"
  },
  {key: ":metro:", src: "images/emoticons/emojis/metro.png", css: "small", title: "metro"},
  {
    key: ":baggage_claim:",
    src: "images/emoticons/emojis/baggage_claim.png",
    css: "small",
    title: "baggage_claim"
  },
  {key: ":accept:", src: "images/emoticons/emojis/accept.png", css: "small", title: "accept"},
  {key: ":wc:", src: "images/emoticons/emojis/wc.png", css: "small", title: "wc"},
  {
    key: ":potable_water:",
    src: "images/emoticons/emojis/potable_water.png",
    css: "small",
    title: "potable_water"
  },
  {
    key: ":put_litter_in_its_place:",
    src: "images/emoticons/emojis/put_litter_in_its_place.png",
    css: "small",
    title: "put_litter_in_its_place"
  },
  {key: ":secret:", src: "images/emoticons/emojis/secret.png", css: "small", title: "secret"},
  {
    key: ":congratulations:",
    src: "images/emoticons/emojis/congratulations.png",
    css: "small",
    title: "congratulations"
  },
  {key: ":m:", src: "images/emoticons/emojis/m.png", css: "small", title: "m"},
  {
    key: ":passport_control:",
    src: "images/emoticons/emojis/passport_control.png",
    css: "small",
    title: "passport_control"
  },
  {
    key: ":left_luggage:",
    src: "images/emoticons/emojis/left_luggage.png",
    css: "small",
    title: "left_luggage"
  },
  {key: ":customs:", src: "images/emoticons/emojis/customs.png", css: "small", title: "customs"},
  {
    key: ":ideograph_advantage:",
    src: "images/emoticons/emojis/ideograph_advantage.png",
    css: "small",
    title: "ideograph_advantage"
  },
  {key: ":cl:", src: "images/emoticons/emojis/cl.png", css: "small", title: "cl"},
  {key: ":sos:", src: "images/emoticons/emojis/sos.png", css: "small", title: "sos"},
  {key: ":id:", src: "images/emoticons/emojis/id.png", css: "small", title: "id"},
  {
    key: ":no_entry_sign:",
    src: "images/emoticons/emojis/no_entry_sign.png",
    css: "small",
    title: "no_entry_sign"
  },
  {
    key: ":underage:",
    src: "images/emoticons/emojis/underage.png",
    css: "small",
    title: "underage"
  },
  {
    key: ":no_mobile_phones:",
    src: "images/emoticons/emojis/no_mobile_phones.png",
    css: "small",
    title: "no_mobile_phones"
  },
  {
    key: ":do_not_litter:",
    src: "images/emoticons/emojis/do_not_litter.png",
    css: "small",
    title: "do_not_litter"
  },
  {
    key: ":non-potable_water:",
    src: "images/emoticons/emojis/non-potable_water.png",
    css: "small",
    title: "non-potable_water"
  },
  {
    key: ":no_bicycles:",
    src: "images/emoticons/emojis/no_bicycles.png",
    css: "small",
    title: "no_bicycles"
  },
  {
    key: ":no_pedestrians:",
    src: "images/emoticons/emojis/no_pedestrians.png",
    css: "small",
    title: "no_pedestrians"
  },
  {
    key: ":children_crossing:",
    src: "images/emoticons/emojis/children_crossing.png",
    css: "small",
    title: "children_crossing"
  },
  {
    key: ":no_entry:",
    src: "images/emoticons/emojis/no_entry.png",
    css: "small",
    title: "no_entry"
  },
  {
    key: ":eight_spoked_asterisk:",
    src: "images/emoticons/emojis/eight_spoked_asterisk.png",
    css: "small",
    title: "eight_spoked_asterisk"
  },
  {
    key: ":eight_pointed_black_star:",
    src: "images/emoticons/emojis/eight_pointed_black_star.png",
    css: "small",
    title: "eight_pointed_black_star"
  },
  {
    key: ":heart_decoration:",
    src: "images/emoticons/emojis/heart_decoration.png",
    css: "small",
    title: "heart_decoration"
  },
  {key: ":vs:", src: "images/emoticons/emojis/vs.png", css: "small", title: "vs"},
  {
    key: ":vibration_mode:",
    src: "images/emoticons/emojis/vibration_mode.png",
    css: "small",
    title: "vibration_mode"
  },
  {
    key: ":mobile_phone_off:",
    src: "images/emoticons/emojis/mobile_phone_off.png",
    css: "small",
    title: "mobile_phone_off"
  },
  {key: ":chart:", src: "images/emoticons/emojis/chart.png", css: "small", title: "chart"},
  {
    key: ":currency_exchange:",
    src: "images/emoticons/emojis/currency_exchange.png",
    css: "small",
    title: "currency_exchange"
  },
  {key: ":aries:", src: "images/emoticons/emojis/aries.png", css: "small", title: "aries"},
  {key: ":taurus:", src: "images/emoticons/emojis/taurus.png", css: "small", title: "taurus"},
  {key: ":gemini:", src: "images/emoticons/emojis/gemini.png", css: "small", title: "gemini"},
  {key: ":cancer:", src: "images/emoticons/emojis/cancer.png", css: "small", title: "cancer"},
  {key: ":leo:", src: "images/emoticons/emojis/leo.png", css: "small", title: "leo"},
  {key: ":virgo:", src: "images/emoticons/emojis/virgo.png", css: "small", title: "virgo"},
  {key: ":libra:", src: "images/emoticons/emojis/libra.png", css: "small", title: "libra"},
  {
    key: ":scorpius:",
    src: "images/emoticons/emojis/scorpius.png",
    css: "small",
    title: "scorpius"
  },
  {
    key: ":sagittarius:",
    src: "images/emoticons/emojis/sagittarius.png",
    css: "small",
    title: "sagittarius"
  },
  {
    key: ":capricorn:",
    src: "images/emoticons/emojis/capricorn.png",
    css: "small",
    title: "capricorn"
  },
  {
    key: ":aquarius:",
    src: "images/emoticons/emojis/aquarius.png",
    css: "small",
    title: "aquarius"
  },
  {key: ":pisces:", src: "images/emoticons/emojis/pisces.png", css: "small", title: "pisces"},
  {
    key: ":ophiuchus:",
    src: "images/emoticons/emojis/ophiuchus.png",
    css: "small",
    title: "ophiuchus"
  },
  {
    key: ":six_pointed_star:",
    src: "images/emoticons/emojis/six_pointed_star.png",
    css: "small",
    title: "six_pointed_star"
  },
  {
    key: ":negative_squared_cross_mark:",
    src: "images/emoticons/emojis/negative_squared_cross_mark.png",
    css: "small",
    title: "negative_squared_cross_mark"
  },
  {key: ":a:", src: "images/emoticons/emojis/a.png", css: "small", title: "a"},
  {key: ":b:", src: "images/emoticons/emojis/b.png", css: "small", title: "b"},
  {key: ":ab:", src: "images/emoticons/emojis/ab.png", css: "small", title: "ab"},
  {key: ":o2:", src: "images/emoticons/emojis/o2.png", css: "small", title: "o2"},
  {
    key: ":diamond_shape_with_a_dot_inside:",
    src: "images/emoticons/emojis/diamond_shape_with_a_dot_inside.png",
    css: "small",
    title: "diamond_shape_with_a_dot_inside"
  },
  {key: ":recycle:", src: "images/emoticons/emojis/recycle.png", css: "small", title: "recycle"},
  {key: ":end:", src: "images/emoticons/emojis/end.png", css: "small", title: "end"},
  {key: ":on:", src: "images/emoticons/emojis/on.png", css: "small", title: "on"},
  {key: ":soon:", src: "images/emoticons/emojis/soon.png", css: "small", title: "soon"},
  {key: ":clock1:", src: "images/emoticons/emojis/clock1.png", css: "small", title: "clock1"},
  {
    key: ":clock130:",
    src: "images/emoticons/emojis/clock130.png",
    css: "small",
    title: "clock130"
  },
  {key: ":clock10:", src: "images/emoticons/emojis/clock10.png", css: "small", title: "clock10"},
  {
    key: ":clock1030:",
    src: "images/emoticons/emojis/clock1030.png",
    css: "small",
    title: "clock1030"
  },
  {key: ":clock11:", src: "images/emoticons/emojis/clock11.png", css: "small", title: "clock11"},
  {
    key: ":clock1130:",
    src: "images/emoticons/emojis/clock1130.png",
    css: "small",
    title: "clock1130"
  },
  {key: ":clock12:", src: "images/emoticons/emojis/clock12.png", css: "small", title: "clock12"},
  {
    key: ":clock1230:",
    src: "images/emoticons/emojis/clock1230.png",
    css: "small",
    title: "clock1230"
  },
  {key: ":clock2:", src: "images/emoticons/emojis/clock2.png", css: "small", title: "clock2"},
  {
    key: ":clock230:",
    src: "images/emoticons/emojis/clock230.png",
    css: "small",
    title: "clock230"
  },
  {key: ":clock3:", src: "images/emoticons/emojis/clock3.png", css: "small", title: "clock3"},
  {
    key: ":clock330:",
    src: "images/emoticons/emojis/clock330.png",
    css: "small",
    title: "clock330"
  },
  {key: ":clock4:", src: "images/emoticons/emojis/clock4.png", css: "small", title: "clock4"},
  {
    key: ":clock430:",
    src: "images/emoticons/emojis/clock430.png",
    css: "small",
    title: "clock430"
  },
  {key: ":clock5:", src: "images/emoticons/emojis/clock5.png", css: "small", title: "clock5"},
  {
    key: ":clock530:",
    src: "images/emoticons/emojis/clock530.png",
    css: "small",
    title: "clock530"
  },
  {key: ":clock6:", src: "images/emoticons/emojis/clock6.png", css: "small", title: "clock6"},
  {
    key: ":clock630:",
    src: "images/emoticons/emojis/clock630.png",
    css: "small",
    title: "clock630"
  },
  {key: ":clock7:", src: "images/emoticons/emojis/clock7.png", css: "small", title: "clock7"},
  {
    key: ":clock730:",
    src: "images/emoticons/emojis/clock730.png",
    css: "small",
    title: "clock730"
  },
  {key: ":clock8:", src: "images/emoticons/emojis/clock8.png", css: "small", title: "clock8"},
  {
    key: ":clock830:",
    src: "images/emoticons/emojis/clock830.png",
    css: "small",
    title: "clock830"
  },
  {key: ":clock9:", src: "images/emoticons/emojis/clock9.png", css: "small", title: "clock9"},
  {
    key: ":clock930:",
    src: "images/emoticons/emojis/clock930.png",
    css: "small",
    title: "clock930"
  },
  {
    key: ":heavy_dollar_sign:",
    src: "images/emoticons/emojis/heavy_dollar_sign.png",
    css: "small",
    title: "heavy_dollar_sign"
  },
  {
    key: ":copyright:",
    src: "images/emoticons/emojis/copyright.png",
    css: "small",
    title: "copyright"
  },
  {
    key: ":registered:",
    src: "images/emoticons/emojis/registered.png",
    css: "small",
    title: "registered"
  },
  {key: ":tm:", src: "images/emoticons/emojis/tm.png", css: "small", title: "tm"},
  {key: ":x:", src: "images/emoticons/emojis/x.png", css: "small", title: "x"},
  {
    key: ":heavy_exclamation_mark:",
    src: "images/emoticons/emojis/heavy_exclamation_mark.png",
    css: "small",
    title: "heavy_exclamation_mark"
  },
  {
    key: ":bangbang:",
    src: "images/emoticons/emojis/bangbang.png",
    css: "small",
    title: "bangbang"
  },
  {
    key: ":interrobang:",
    src: "images/emoticons/emojis/interrobang.png",
    css: "small",
    title: "interrobang"
  },
  {key: ":o:", src: "images/emoticons/emojis/o.png", css: "small", title: "o"},
  {
    key: ":heavy_multiplication_x:",
    src: "images/emoticons/emojis/heavy_multiplication_x.png",
    css: "small",
    title: "heavy_multiplication_x"
  },
  {
    key: ":heavy_plus_sign:",
    src: "images/emoticons/emojis/heavy_plus_sign.png",
    css: "small",
    title: "heavy_plus_sign"
  },
  {
    key: ":heavy_minus_sign:",
    src: "images/emoticons/emojis/heavy_minus_sign.png",
    css: "small",
    title: "heavy_minus_sign"
  },
  {
    key: ":heavy_division_sign:",
    src: "images/emoticons/emojis/heavy_division_sign.png",
    css: "small",
    title: "heavy_division_sign"
  },
  {
    key: ":white_flower:",
    src: "images/emoticons/emojis/white_flower.png",
    css: "small",
    title: "white_flower"
  },
  {key: ":100:", src: "images/emoticons/emojis/100.png", css: "small", title: "100"},
  {
    key: ":heavy_check_mark:",
    src: "images/emoticons/emojis/heavy_check_mark.png",
    css: "small",
    title: "heavy_check_mark"
  },
  {
    key: ":ballot_box_with_check:",
    src: "images/emoticons/emojis/ballot_box_with_check.png",
    css: "small",
    title: "ballot_box_with_check"
  },
  {
    key: ":radio_button:",
    src: "images/emoticons/emojis/radio_button.png",
    css: "small",
    title: "radio_button"
  },
  {key: ":link:", src: "images/emoticons/emojis/link.png", css: "small", title: "link"},
  {
    key: ":curly_loop:",
    src: "images/emoticons/emojis/curly_loop.png",
    css: "small",
    title: "curly_loop"
  },
  {
    key: ":wavy_dash:",
    src: "images/emoticons/emojis/wavy_dash.png",
    css: "small",
    title: "wavy_dash"
  },
  {
    key: ":part_alternation_mark:",
    src: "images/emoticons/emojis/part_alternation_mark.png",
    css: "small",
    title: "part_alternation_mark"
  },
  {key: ":trident:", src: "images/emoticons/emojis/trident.png", css: "small", title: "trident"},
  {
    key: ":black_square:",
    src: "images/emoticons/emojis/black_square.png",
    css: "small",
    title: "black_square"
  },
  {
    key: ":white_square:",
    src: "images/emoticons/emojis/white_square.png",
    css: "small",
    title: "white_square"
  },
  {
    key: ":white_check_mark:",
    src: "images/emoticons/emojis/white_check_mark.png",
    css: "small",
    title: "white_check_mark"
  },
  {
    key: ":black_square_button:",
    src: "images/emoticons/emojis/black_square_button.png",
    css: "small",
    title: "black_square_button"
  },
  {
    key: ":white_square_button:",
    src: "images/emoticons/emojis/white_square_button.png",
    css: "small",
    title: "white_square_button"
  },
  {
    key: ":black_circle:",
    src: "images/emoticons/emojis/black_circle.png",
    css: "small",
    title: "black_circle"
  },
  {
    key: ":white_circle:",
    src: "images/emoticons/emojis/white_circle.png",
    css: "small",
    title: "white_circle"
  },
  {
    key: ":red_circle:",
    src: "images/emoticons/emojis/red_circle.png",
    css: "small",
    title: "red_circle"
  },
  {
    key: ":large_blue_circle:",
    src: "images/emoticons/emojis/large_blue_circle.png",
    css: "small",
    title: "large_blue_circle"
  },
  {
    key: ":large_blue_diamond:",
    src: "images/emoticons/emojis/large_blue_diamond.png",
    css: "small",
    title: "large_blue_diamond"
  },
  {
    key: ":large_orange_diamond:",
    src: "images/emoticons/emojis/large_orange_diamond.png",
    css: "small",
    title: "large_orange_diamond"
  },
  {
    key: ":small_blue_diamond:",
    src: "images/emoticons/emojis/small_blue_diamond.png",
    css: "small",
    title: "small_blue_diamond"
  },
  {
    key: ":small_orange_diamond:",
    src: "images/emoticons/emojis/small_orange_diamond.png",
    css: "small",
    title: "small_orange_diamond"
  },
  {
    key: ":small_red_triangle:",
    src: "images/emoticons/emojis/small_red_triangle.png",
    css: "small",
    title: "small_red_triangle"
  },
  {
    key: ":small_red_triangle_down:",
    src: "images/emoticons/emojis/small_red_triangle_down.png",
    css: "small",
    title: "small_red_triangle_down"
  },
  {key: ":shipit:", src: "images/emoticons/emojis/shipit.png", css: "small", title: "shipit"}
|];

let emojiMap =
  Array.fold_left
    (fun run (emoji: State.emoji) => State.EmojiPairs.(add emoji.key emoji run))
    State.EmojiPairs.empty
    emoticons;
