import pygame

pygame.init()

class GameSprite(pygame.sprite.Sprite):
    def __init__(self,player_image,player_x,player_y,player_speed):
        super().__init__()
        self.image = pygame.transform.scale(pygame.image.load(player_image), (65,65))
        self.speed = player_speed
        self.rect = self.image.get_rect()
        self.rect.x = player_x
        self.rect.y = player_y

    def reset(self):
        window.blit(self.image , (self.rect.x, self.rect.y))



class Wall(pygame.sprite.Sprite):
    def __init__(self,color_1,color_2,color_3,wall_x,wall_width,wall_height,rect):
        super().__init__()
        self.color_1 = color_1
        self.color_2 = color_2
        self.color_3 = color_3
        self.width= wall_width
        self.height = wall_height
        self.image = Surface((self.width,self.height))
        self.image.fill((color_1,color_2,color_3))
        self.rect = self.image.get_rect()
        self.rect.x=wall_x
        self.rect.y=wall_y
    def draw_wall(self):
        window.blit(self.image, (self.rect.x,self.rect.y))
        w1.draw_wall(0, 0, 100,40,40,100,400)
        w2.draw_wall(184, 88, 255,20,20,100,300)
        w3.draw_wall(80, 80, 255,30,30,100,200)


class Player(GameSprite):
    def update(self):
        keys = pygame.key.get_pressed()
        if keys[pygame.K_a] and self.rect.x > 5:
            self.rect.x -= self.speed
        if keys[pygame.K_d] and self.rect.x < win_width - 80:
            self.rect.x += self.speed
        if keys[pygame.K_w] and self.rect.y > 5:
            self.rect.y -= self.speed
        if keys[pygame.K_s] and self.rect.y < win_height:
            self.rect.y += self.speed


class Soviet(GameSprite):
    direction = 'left'
    def update(self):
        if self.rect.x <= 470:
            self.direction='right'
        if self.rect.x >= win_width -85:
            self.direction = 'left'
        
        if self.direction == 'left':
            self.rect.x -= self.speed
        else:
            self.rect.x += self.speed

win_width = 700
win_height= 500
window = pygame.display.set_mode((win_width,win_height))
pygame.display.set_caption("В поисках своей совести")
background = pygame.transform.scale(pygame.image.load('background.jpg'), (win_width,win_height))

player = Player('hero.png', 5, win_height-80,4)
monster = Soviet('cyborg.png', win_width-80,280,2)
final = GameSprite('treasure.png', win_width - 120 ,win_height - 80,0)

game = True 
finish = False
clock=pygame.time.Clock()
FPS = 60

pygame.mixer.init()
pygame.mixer.music.load('jungles.ogg')
pygame.mixer.music.play()

while game:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            game = False

    window.blit(background, (0,0))
    player.reset()
    monster.reset()
    final.reset()

    player.update()
    monster.update()
    pygame.display.update()
    clock.tick(FPS)
